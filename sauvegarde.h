#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "clientdata.h"
#include <QTimer>
#include <QSettings>
#include <QGeoRoute>
#include <QFileInfo>


using namespace std;
class Sauvegarde : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int position READ getPosition WRITE setPosition)
    Q_PROPERTY(QString idCanal READ getIdCanal WRITE setIdCanal)
    Q_PROPERTY(QString nomCanal READ getNomCanal WRITE setNomCanal)
    Q_PROPERTY(bool leFichierExiste READ getLeFichierExiste)

    Q_PROPERTY(QList<QString> idCanalChargement READ getIdCanalChargement)
    Q_PROPERTY(QList<QString> nomCanalChargement READ getNomCanalChargement)
private:
    int position;
    QString idCanal;
    QString nomCanal;
    bool leFichierExiste;

    QList<QString> idCanalChargement;
    QList<QString> nomCanalChargement;

public:
    Sauvegarde();
    ~Sauvegarde();
    Q_INVOKABLE void sauvegarderDesCanaux();
    Q_INVOKABLE void chargerLesCanaux();
    int getPosition() const;
    void setPosition(int value);
    QString getIdCanal() const;
    void setIdCanal(const QString &value);
    void setNomCanal(const QString &value);
    QString getNomCanal() const;
    QList<QString> getIdCanalChargement() const;
    QList<QString> getNomCanalChargement() const;
    bool getLeFichierExiste() const;
};

#endif // CONTROLLER_H
