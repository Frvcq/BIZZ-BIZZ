#ifndef CLIENTDATA_H
#define CLIENTDATA_H
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QJsonObject"
#include "QJsonDocument"
#include <QDebug>
#include <iostream>
#include <QPoint>
#include <QJsonArray>
#include <QSslSocket>

using namespace std;
class ClientData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> lesNomsDesChamps READ getLesNomsDesChamps NOTIFY lesNomsDesChampsChanged)
    Q_PROPERTY(QList<QPointF> lesPointsGraphique READ getLesPointsGraphique NOTIFY lesPointsGraphiqueChanged)
    Q_PROPERTY(int nbChamps READ getNbChamps)
    Q_PROPERTY(bool erreurJson READ getErreurJson)
    Q_PROPERTY(bool erreurReseau READ getErreurReseau)
    Q_PROPERTY(bool erreurHTTPS READ getErreurHTTPS)
    Q_PROPERTY(bool erreurIllegalValue READ getErreurIllegalValue)
    Q_PROPERTY(bool erreurJsonFormat READ getErreurJsonFormat)
    Q_PROPERTY(bool erreurJsonNull READ getErreurJsonNull)
    Q_PROPERTY(QString url READ getUrl WRITE setUrl)


private:
    /** attribut qui permet de manipuler la liason réseau */
    QNetworkAccessManager *manager;
    /** attribut qui traite le réseau */
    QNetworkReply *reponseReseau;
    /** attribut qui conserve et traite l'objet JSON reçue */
    QJsonObject donneeCanal;
    /** attribut qui permet de recevoir la reponse réseau */
    QNetworkRequest requete;
    /** attribut qui conserve le nom des champs une fois l'objet JSON parsé */
    QList <QString> lesNomsDesChamps;
    /** attribut qui conserve les coordonnées de points de chaques mesures. X => date , Y => La mesure */
    QList <QPointF> lesPointsGraphique;
    /** attribut qui conserve l'objet JSON reçue temporairement pour assurer sa bonne réception */
    QByteArray buffer;
    /** le nombre des champs */
    int nbChamps;
    /** savoir si l'erreur est lié à l'objet json non intègre */
    bool erreurJson;
    /** savoir si l'erreur est lié au réseau */
    bool erreurReseau;
    /** savoir si l'erreur est lié au SSL */
    bool erreurHTTPS;
    /** savoir si l'erreur est lié à une chose qui n'est pas un objet JSON*/
    bool erreurIllegalValue;
    /** savoir si l'erreur est lié au format de la date reçue*/
    bool erreurFormatDate;
    /** savoir si l'erreur est lié au format de l'objet JSON*/
    bool erreurJsonFormat;
    /** savoir si l'erreur est lié à un objet JSON vide */
    bool erreurJsonNull;
    /** l'url du serveur distant */
    QString url;


public:
    ClientData();
    ~ClientData();

    Q_INVOKABLE void parserData();

    Q_INVOKABLE void initialisation(QString _url);

    QList<QString> getLesNomsDesChamps() const;

    QList<QPointF> getLesPointsGraphique() const;

    int getNbChamps() const;

    bool getErreurJson() const;

    bool getErreurReseau() const;

    bool getErreurHTTPS() const;

    bool getErreurIllegalValue() const;

    bool getErreurJsonFormat() const;

    QString getUrl() const;

    void setUrl(const QString &value);

    bool getErreurJsonNull() const;

public slots:
    void onQnetworkAccessManagerReplyFinished();
    void onQnetworkAccessManagerReadyRead();
    void onQnetworkAccessManagerError();
    void onQnetworkAccessManagerSslErrors();

signals:
    void lesNomsDesChampsChanged();
    void lesPointsGraphiqueChanged();
    void connexionEchec();
    void jsonEchec();
    void httpsEchec();
    void erreurIllegal();
    void erreurFormatDateSignal();
    void erreurJsonFormatSignal();
    void creationClient();
    void jsonNull();
};

#endif // CLIENTDATA_H
