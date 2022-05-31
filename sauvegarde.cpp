#include "sauvegarde.h"
/**
  @file sauvegarde.cpp
  @brief implémentation de la classe sauvegarde.cpp
  @version 1.0
  @author Farvacque Flavian
  @date 31/05/2022
  @details Classe permettant de sauvegarder et charger nos boutonns dans une fichier ini
  */
/**
 * @brief Sauvegarde::getPosition accesseur de l'attribut position
 * @return  retourne la position du bouton dans la liste de l'objet repeater dans main.qml
 */
int Sauvegarde::getPosition() const
{
    return position;
}
/**
 * @brief Sauvegarde::setPosition mutateur de l'attribut position
 * @param value
 */
void Sauvegarde::setPosition(int value)
{
    position = value;
}
/**
 * @brief Sauvegarde::getIdCanal accesseur de l'attribut idCanal
 * @return
 */
QString Sauvegarde::getIdCanal() const
{
    return idCanal;
}
/**
 * @brief Sauvegarde::setIdCanal mutateur de l'attribut idCanal
 * @param value
 */
void Sauvegarde::setIdCanal(const QString &value)
{
    idCanal = value;
}
/**
 * @brief Sauvegarde::setNomCanal mutateur de l'attibut nomCanal
 * @param value
 */
void Sauvegarde::setNomCanal(const QString &value)
{
    nomCanal = value;
}
/**
 * @brief Sauvegarde::getNomCanal accesseur de l'attribut nomCanal
 * @return
 */
QString Sauvegarde::getNomCanal() const
{
    return nomCanal;
}
/**
 * @brief Sauvegarde::getIdCanalChargement accesseur de l'attribut idCanalChargement
 * @return
 */
QList<QString> Sauvegarde::getIdCanalChargement() const
{
    return idCanalChargement;
}
/**
 * @brief Sauvegarde::getNomCanalChargement accesseur de l'attribut nomCanalChargement
 * @return
 */
QList<QString> Sauvegarde::getNomCanalChargement() const
{
    return nomCanalChargement;
}

/**
 * @brief Sauvegarde::getLeFichierExiste accesseur de l'attribut leFichierExiste
 * @return
 */
bool Sauvegarde::getLeFichierExiste() const
{
    return leFichierExiste;
}
/**
 * @brief Sauvegarde::Sauvegarde constructeur de la classe Sauvegarde , par défaut leFichierExiste est
 * mis en false car on part du principe que l'on a pas de fichier dès la première ouverture
 */
Sauvegarde::Sauvegarde()
{
leFichierExiste = false;
}
/**
 * @brief Sauvegarde::~Sauvegarde destructeur de la classe Sauvegarde
 */
Sauvegarde::~Sauvegarde()
{

}
/**
 * @brief Sauvegarde::sauvegarderDesCanaux méthode permettant de sauvegarde les informations de nos
 * boutons présent dans main.qml afin de retrouver nos canaux dans une future utilisation si l'on
 * quitte l'application
 */
void Sauvegarde::sauvegarderDesCanaux()
{

    QString champBouton = "BOUTON" + QString::number(position);
    QString leFichierIni = "Canal.ini";
    QSettings paramSocket(leFichierIni,QSettings::IniFormat);
    paramSocket.beginGroup(champBouton);
    paramSocket.setValue("idCanal",idCanal);
    paramSocket.setValue("nomCanal",nomCanal);
    paramSocket.endGroup();
}
/**
 * @brief Sauvegarde::chargerLesCanaux méthode permettant de charger les informations présentent dans
 * canal.ini afin de retrouver nos canaux qui ont été sauvegardés ultérieurement
 */

void Sauvegarde::chargerLesCanaux()
{
    QString nomFichierIni="Canal.ini";
    QFileInfo testFichier(nomFichierIni);
    //on vérifie si la chose  existe et qu'elle est un fichier
    if (testFichier.exists() && testFichier.isFile()){
        leFichierExiste = true;
        QSettings paramSocket(nomFichierIni,QSettings::IniFormat);
        //on a le droit que a 15 boutons maximums
        for (int i =0 ;i<15;i++){
            idCanalChargement.append(paramSocket.value("BOUTON"+QString::number(i)+"/idCanal").toString());
            nomCanalChargement.append(paramSocket.value("BOUTON"+QString::number(i)+"/nomCanal").toString());
        }
    }
    // si le fichier n'existe pas alors on prévient leFichierExiste
    else {
        leFichierExiste = false;
    }
}
