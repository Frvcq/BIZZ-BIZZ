/*
  fonction qui vérifie si une chaine de caractère contient une séquence précise au début de celle ci
  chaineCharactere => la chaine de caractère que l'on souhaite vérifier
  sequence => la séquence de caratère que l'on souhaite vérifier
*/
function contenirSequenceDebut(chaineCharactere,sequence){
    let contienSequence = false;
    let regex = new RegExp("^"+sequence+".*")
    console.log("regex contenir sequence : "+regex);
    if (chaineCharactere.search(regex)!==-1) {
        contienSequence = true;
    }

    console.log("regexp premiere occurence : "+chaineCharactere.search(regex));
    return contienSequence;
}
/*Fonction permettant d'afficher les courbes sur les graphiques en utilisant le tableau de QpointF provenant
de l'objet de type ClientData
client => objet de type  ClientData qui retourne les données de l'objet JSON
chart => le graphique sur lequel on souhaite mettre les points
courbeField => la courbe lié au chart
axeX => l'axe X lié au chart
axeY => l'axe Y lié au chart
fieldnum => le numéro du graphique en position (adapté spécialement au JSON retourné pour mieu récupérer les données)
*/
function genererGraphique(client,chart,courbeField,axeX,axeY,fieldnum){
    let control=0;
    let dateParse;
    let maxX=0;
    let minX=0;
    // iniatilisation des minima et maxima
    let maxY=client.lesPointsGraphique[fieldnum].y;
    let minY=client.lesPointsGraphique[fieldnum].y;
    // mettre à jour le nom du canal dans la banderolle noir
    texteBanderolle.text=client.lesNomsDesChamps[1];
    //si notre graphique est dans les champs sinon le rendre invisible
    if(fieldnum<client.nbChamps){
        chart.visible = true;
        //on récupère la date de l'indice 0
        minX = new Date(client.lesPointsGraphique[0].x);
        for(let i =fieldnum;i<client.lesPointsGraphique.length;i+=client.nbChamps){
            //on convertie la date qui est en milliseconde since epoch en date normal
            dateParse = new Date(client.lesPointsGraphique[i].x);
            //on cherche le nouveau max
            if (client.lesPointsGraphique[i].y > maxY){
                maxY=client.lesPointsGraphique[i].y;
            }
            else{
                //sinon on cherche le nouveau min
                if(client.lesPointsGraphique[i].y<minY){
                    minY = client.lesPointsGraphique[i].y;
                }
            }
            //on recherche la date la plus récente
            if (client.lesPointsGraphique[i].x>maxX){
                maxX=dateParse;

            }
            //on ajoute notre point sur le graphique
            courbeField.append(dateParse.getTime(),client.lesPointsGraphique[i].y);

        }
        //on affiche le nom des données sur le graphique , +5 car le nom des champs commencent dès la 5 ième donnée
        courbeField.name = client.lesNomsDesChamps[5+fieldnum];
        //on enleve le format des points car sinon c'est illisible
        courbeField.pointLabelsFormat="";

        //par souci de lecture augmentation de l'axe des ordonnés
        if(maxY>10000){
            axeY.max=maxY+15;
        }
        else {
            axeY.max=maxY+0.1;
        }


        axeY.min=minY;

        axeX.max=maxX;
        axeX.min=minX;

    }
    else {
        chart.visible=false;

    }
}


/*fonction affichant les différentes erreurs existante retournées par l'objet client de type ClientData
*/
function erreur(){
    textAreaErreur.visible = true;
    texteBanderolle.text="NO DATA"
    texteBanderolle.color = "red";
    console.log("l'url : "+client.url)
    if (client.erreurJson === true){
        textAreaErreur.text = "\n Les données JSON ne sont pas \n arrivé correctement , veuillez \n quitter votre"+
                " canal\n et le relancer."
    }
    else{
        if (client.erreurReseau === true){
            if (contenirSequenceDebut(client.url,"https")){
                textAreaErreur.text = " Le protocol HTTPS n'est pas pris\n en charge pour des raisons \n juridiques";
            }
            else {
                textAreaErreur.text = "\n La connexion n'a pas pue être \n établi. Vérifier si vous êtes\n connecté" +
                        " en WI-FI ou en données\n mobiles , Si vous l'êtes cela veut \n dire que votre serveur distant"+
                        " est \ndéconnecté ou que l'url est\n invalide."
            }


        }
        else {
            if(client.erreurHTTPS === true){
                textAreaErreur.text = " Le protocol HTTPS n'est pas pris\n en charge pour des raisons \n juridiques"
            }
            else {
                if (client.erreurIllegalValue === true){
                    textAreaErreur.text = " Le canal est inexistant";
                }
                else {
                    if(client.erreurJsonFormat === true) {
                        textAreaErreur.text = " Format de l'objet \nJSON non valide";

                    }
                    else{
                        if(client.erreurJsonNull === true){
                            textAreaErreur.text = " Aucun objet Json reçu de la \n part du serveur distant";

                        }
                    }
                }
            }
        }

    }
}
/*fonction qui récupère l'id canal et l'url de la page formulaire.qml
*/
function getURL(){
    let url;
    let idcanal;
    url =textInputURL.text;
    idcanal = textInputIdCanal.text;
    url = url +"/Ruche/channels/"+idcanal+"/feeds.json?results=60";
    return url;
}
/* fonction qui récupère l'id canal du bouton et concatène celui ci pour faire l'url
  lié au bouton de la page main.qml
  bouton => le bouton sur lequel on souhaite récupérer les informations
*/
function getURLBouton(bouton){
    let idCanalTransition;
    let url;
    let idCanal ="";
    idCanalTransition = bouton.text;
    //on cherche une suite de chiffre ; ce qui représente un canal
    let regex = new RegExp("[1-9]");
    for (let i = idCanalTransition.search(regex);i<idCanalTransition.length;i++){
        idCanal = idCanal +idCanalTransition[i];
    }
    url = "http://touchardinforeseau.servehttp.com/Ruche/channels/"+idCanal+"/feeds.json?results=60";
    return url;
}

/* fonction qui ajoute un bouton sur la page principal en gardant en mémoire les informations suivantes :
  le nom du canal et l'id du canal
*/
function ajouterBouton(){
    let maPosition=0;
    for (let i = 0 ; i<15;i++){
        //on vérifie si le bouton est invisible , si c'est le cas cela veut dire qu'il n'a aucune données
        if (!(repeaterBouton.itemAt(i).visible)){
            maPosition = i;
            break;
        }

    }
    // on regarde dans le repeater la position de notre bouton et on le remplis
    repeaterBouton.itemAt(maPosition).text = client.lesNomsDesChamps[1]+", canal : "+textInputIdCanal.text;
    repeaterBouton.itemAt(maPosition).visible = true;
    //on met a jour les attributs de l'objet laSauvegarde
    laSauvegarde.position = maPosition;
    laSauvegarde.idCanal = textInputIdCanal.text;
    laSauvegarde.nomCanal = client.lesNomsDesChamps[1];
    //on sauvegarde les canaux avec les nouvelles valeurs des attributs
    laSauvegarde.sauvegarderDesCanaux();

}
function chargerLesBoutons(){
    let i =0;
    //on charge le fichier pour mettre à jour les attributs de l'objet laSauvegarde
    laSauvegarde.chargerLesCanaux();
    // on vérifie si le fichier existe pour éviter de remplir nos boutons avec des undifined
    if (laSauvegarde.leFichierExiste == true){
        do {
            //on met à jour le texte de notre bouton et on le rend visible
            repeaterBouton.itemAt(i).text = laSauvegarde.nomCanalChargement[i] +", canal : "+laSauvegarde.idCanalChargement[i];
            repeaterBouton.itemAt(i).visible = true;
            i++
            //si l'on a plus de données à afficher on quitte la boucle
        }while(laSauvegarde.idCanalChargement[i]!=="");

    }


}

