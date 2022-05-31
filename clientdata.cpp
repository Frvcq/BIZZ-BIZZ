/**
  @file clientdata.cpp
  @brief implémentation de la classe clientData.cpp
  @version 1.0
  @author Farvacque Flavian
  @date 09/05/2022
  @details Classe permettant de récupérer et décoder l'objet JSON retourné
  le serveur distant.
  */
#include "clientdata.h"

/**
 * @brief ClientData::getLesNomsDesChamps
 * @details accesseur de l'attribut lesNomsDesChamps
 * @return
 */
QList<QString> ClientData::getLesNomsDesChamps() const
{
    return lesNomsDesChamps;
}

/**
 * @brief ClientData::getLesPointsGraphique
 * @details accesseur de l'attribut lesPointsGraphique
 * @return
 */
QList<QPointF> ClientData::getLesPointsGraphique() const
{
    return lesPointsGraphique;
}

/**
 * @brief ClientData::getNbChamps
 * @details accesseur de l'attribut nbChamps
 * @return
 */

int ClientData::getNbChamps() const
{
    return nbChamps;
}

/**
 * @brief ClientData::getErreurJson
 * @details accesseur de l'attribut erreurJson
 * @return
 */
bool ClientData::getErreurJson() const
{
    return erreurJson;
}
/**
 * @brief ClientData::getErreurReseau
 * @details accesseur de l'attribut erreurReseau
 * @return
 */
bool ClientData::getErreurReseau() const
{
    return erreurReseau;
}
/**
 * @brief ClientData::getErreurHTTPS
 * @details accesseur de l'attribut erreurHTTPS
 * @return
 */
bool ClientData::getErreurHTTPS() const
{
    return erreurHTTPS;
}
/**
 * @brief ClientData::getErreurIllegalValue
 * @details accesseur de l'attribut erreurIllegalValue
 * @return
 */
bool ClientData::getErreurIllegalValue() const
{
    return erreurIllegalValue;
}
/**
 * @brief ClientData::getErreurJsonFormat
 * @details accesseur de l'attribut erreurJsonFormat
 * @return
 */
bool ClientData::getErreurJsonFormat() const
{
    return erreurJsonFormat;
}
/**
 * @brief ClientData::getUrl
 * @details accesseur de l'attribut url
 * @return
 */
QString ClientData::getUrl() const
{
    return url;
}
/**
 * @brief ClientData::setUrl
 * @details mutateur de l'attribut url
 * @param value
 */
void ClientData::setUrl(const QString &value)
{
    url = value;
}
/**
 * @brief ClientData::getErreurJsonNull
 * @details récupération de l'attribut erreurJsonNull
 * @return
 */
bool ClientData::getErreurJsonNull() const
{
    return erreurJsonNull;
}
/**
 * @brief ClientData::ClientData
 * @details constructeur de la classe , il est vide due aux spécificités de QML. Tout
 * est réellement initialisé dans la méthode ClientData::initialisation()
 */
ClientData::ClientData()
{

}
/**
 * @brief ClientData::~ClientData
 */
ClientData::~ClientData()
{
    delete this;
}
/**
 * @brief ClientData::parserData
 * @details méthode permettant de parser l'objet JSON afin de rendre les données traitable par l'environnement.
 *  Elle trouve puis extrait les données en parcourant l'objet JSON en commençant par le tableau channel puis
 *  le tableau feeds qui lui même contient 60 sous tableaux de valeurs composés de "created_at , entry_id,field1,
 *  field2 ... field8 ". Si l'objet contient au total 6 field sur les 8 retournées au maximum on doit traiter
 *  seulement les 6 fields de chaques sous tableaux.
 */
void ClientData::parserData()
{
    buffer.clear();
    QString formatAgregator = "yyyy-MM-ddThh-mm-ssZ"; //agregator
    QString formatThingSpeak = "yyyy-MM-ddThh:mm:ssZ"; //thingspeak
    QString recuperationDate;
    QVariantMap structure=donneeCanal.toVariantMap();
    QMap<QString, QVariant> sousStructure;
    QString nomChampField;
    QString nomChampHorsField;
    QList<QString> listeChampsField;

    if (structure.contains("channel"))
    {
        sousStructure=structure["channel"].toMap(); // descend dans l'arborescence pour récupérer les champs qui sont des tableaux

        nomChampHorsField = sousStructure["id"].toString();
        lesNomsDesChamps.append(nomChampHorsField);

        nomChampHorsField = sousStructure["name"].toString();
        lesNomsDesChamps.append(nomChampHorsField);

        nomChampHorsField = sousStructure["description"].toString();
        lesNomsDesChamps.append(nomChampHorsField);

        nomChampHorsField = sousStructure["latitude"].toString();
        lesNomsDesChamps.append(nomChampHorsField);

        nomChampHorsField = sousStructure["longitude"].toString();
        lesNomsDesChamps.append(nomChampHorsField);


        nbChamps=0;
        //on récupère le nom des champs
        for (int i=0;i<sousStructure.size();i++){
            nomChampField="field"+QString::number(i);
            if (sousStructure.contains(nomChampField)){
                listeChampsField.append(nomChampField);
                nomChampField = sousStructure[nomChampField].toString();
                lesNomsDesChamps.append(nomChampField);
                nbChamps++;
            }

        }
        nomChampHorsField = sousStructure["elevation"].toString();
        lesNomsDesChamps.append(nomChampHorsField);

        nomChampHorsField = sousStructure["last_entry_id"].toString();
        lesNomsDesChamps.append(nomChampHorsField);
        // si on a des "feeds"
        if (structure.contains("feeds"))
        {
            QJsonArray tab=donneeCanal.take("feeds").toArray();
            for(int i=0;i<tab.size();i++)
            {
                QDateTime pointX;
                QVariantMap obj=tab[i].toObject().toVariantMap();
                if (obj.contains("created_at"))
                {
                    recuperationDate = obj["created_at"].toString();

                    //vérification de la date
                    if (recuperationDate.contains(":") ){
                        pointX=QDateTime::fromString(recuperationDate,formatThingSpeak);
                    }
                    else {
                        if(recuperationDate.contains("-"))
                        {
                            pointX=QDateTime::fromString(recuperationDate,formatAgregator);
                        }
                        else {
                            erreurFormatDate = true;
                            emit erreurFormatDateSignal();
                        }
                    }
                }
                //pour chaque sortie qui correspond au nomField on ajoute le point dans la liste
                foreach (QString nomField, listeChampsField) {
                    if (obj.contains(nomField))
                    {
                        lesPointsGraphique.append(QPointF(pointX.toMSecsSinceEpoch(),obj[nomField].toDouble()));
                    }
                }
            }
        }
        emit lesPointsGraphiqueChanged();
    }
    else {
        erreurJsonFormat = true;
        emit erreurJsonFormatSignal();
    }

}
/**
 * @brief ClientData::initialisation
 * @param _url url retourné par la zone de texte de l'interface graphique
 * @details méthode mettant à jour les attributs de la classe , servant de pseudo constructeur
 *  due aux spécificités de QML
 */
void ClientData::initialisation(QString _url)
{
    buffer.clear();
    erreurJsonFormat = false;
    erreurFormatDate = false;
    erreurJson = false;
    erreurReseau = false;
    erreurIllegalValue = false;
    erreurHTTPS = false;
    erreurJsonNull = false;
    url = _url;

    manager = new QNetworkAccessManager(this);
    requete.setUrl(QUrl(url));
    requete.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
    reponseReseau = manager->get(requete);
    reponseReseau->setReadBufferSize(100024);

    connect(reponseReseau, &QIODevice::readyRead,
            this, &ClientData::onQnetworkAccessManagerReadyRead);
    connect(reponseReseau, &QNetworkReply::errorOccurred,
            this, &ClientData::onQnetworkAccessManagerError);
    connect(reponseReseau, &QNetworkReply::sslErrors,
            this, &ClientData::onQnetworkAccessManagerSslErrors);

}


void ClientData::onQnetworkAccessManagerReplyFinished()
{
    manager->deleteLater();
}
/**
 * @brief ClientData::onQnetworkAccessManagerReadyRead
 * @details récupération des données émisent par le seveur distant en connexion direct.
 */
void ClientData::onQnetworkAccessManagerReadyRead()
{
    QJsonDocument documentJson;
    QJsonParseError erreur;
    qDebug()<<"reception de  "<<reponseReseau->bytesAvailable()<<" octets";
    buffer.append(reponseReseau->readAll());
    documentJson= QJsonDocument::fromJson(buffer,&erreur);

    if (erreur.error == QJsonParseError::UnterminatedObject ||erreur.error == QJsonParseError::UnterminatedString ){


    }
    else {
        if (buffer.toInt() == -1){
            erreurIllegalValue = true;
            emit erreurIllegal();
        }
        else {
            // on vérifie si l'objet est vide
            if (documentJson.isNull()){
                erreurJsonNull = true;
                emit jsonNull();

            }
            else {
                if (documentJson.object().isEmpty()==false){
                    //on vérifie si c'st un objet
                    if (documentJson.isObject()){
                        donneeCanal =(documentJson.object());
                        parserData();
                    }

                }
                else {
                    erreurJson = true;
                    emit jsonEchec();
                }

            }
        }
    }

}

/**
 * @brief ClientData::onQnetworkAccessManagerError
 * @details en cas de connexion directe au serveur inexistante
 */
void ClientData::onQnetworkAccessManagerError()
{
    erreurReseau = true;
    manager->deleteLater();
    manager->disconnect();
    emit connexionEchec();

}
/**
 * @brief ClientData::onQnetworkAccessManagerSslErrors
 * @details en cas d'erreur SSL
 */
void ClientData::onQnetworkAccessManagerSslErrors()
{
    erreurHTTPS = true;
    emit httpsEchec();
    manager->deleteLater();
    manager->disconnect();
}
