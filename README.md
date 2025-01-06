# Projet d'analyse avec ROOT

Ce projet contient des scripts et des fichiers pour effectuer des analyses en utilisant ROOT.

## Prérequis

Avant de commencer, assurez-vous d'avoir les éléments suivants installés sur votre système :
- **Bash** (inclus par défaut dans la plupart des systèmes Unix/Linux)
- **ROOT** (voir ci-dessous pour l'installation)
- Un compilateur C++ (g++, clang, etc.)

---

## Installation de ROOT

Téléchargez la dernière version de ROOT depuis le site officiel :
https://root.cern/install/

Suivez les instructions fournies pour votre système d'exploitation.

## Execution des scripts

### generate.C

Ce script sert a la génération de pseudo-données qui sont enregistrées dans histogramme.root.
Pour l'exécuter il faut d'abord ouvrir une frame-work ROOT.

```bash
root
.x generate.C
```

### scan.C

Ce script sert au scan du likelihood de histogramme.root.
Celui-ci nous permet de savoir si notre analyse est juste pour ensuite traiter d'autres données.
De la même manière :

```bash
root
.x scan.C
```

### challenge.C

Il s'agit d'un bonus qui réalise le scan du likelihood sur un jeu de données inconnu : challenge.root.

```bash
root
.x challenge.C
```

## Rapport

Vous trouverez le fichier [Rapport_ROOT.pdf](Rapport_ROOT.pdf) qui vous donnera des informations supplémentaires sur les formules utilisées et sur l'analyse post-traitement.

## Contributeurs

Merci aux personnes ayant contribué à ce projet :  
- [MAAMAATUAIAHUTAPU Tetautahi](https://github.com/tmaamaatua)

## Licence

Ce projet est sous licence **MIT**. Consultez le fichier [LICENSE](LICENSE) pour plus de détails.

