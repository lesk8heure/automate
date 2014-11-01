Projet d'automate cellulaire 2D à signaux.

Toujours branch lorsque vous faites de modifs. On en merge QUE si une autre personne a vérifié le travail et approuvé.

Rapidement, pour pouvoir bosser tranquilement de chez vous, si vous n'avez jamais utilisé git :

Lire ce tuto : http://putaindecode.fr/posts/git/versionner-avec-git/
Il est relativement clair, ne s'embête pas avec trop de détails

Sinon, pour aller plus loin, utilisez celui-là : https://fr.atlassian.com/git/tutorials/setting-up-a-repository

Dans votre cas, vous allez créer une copie de ce repo

Donc, sur linux

> apt-get install git

> git config --global user.name "<votre pseudo>"
> git config --global user.email "<une adresse email de contact>"

Maintenant, tu vas aller sur github, te créer un compte.

Quand c'est fait, tu retournes sur ce repo /Chantesprit/automate. Et tu verras qu'en haut à gauche, y'a un bouton "fork"
Tu cliques dessus.

Voilà, le repo principal est copié sur ton compte de github.

Tu retourne sur linux, et on va commencer les choses sérieuses.

Tu vas créer un clone de ton repo sur ta machine, pour bosser en local.

pour cela :

> git clone https://github.com/<ton pseudo>/automate automate
ça va te copier le repo dans un dossier nommé automate à partir de la ou tu te trouves quand tu lanceras la commande

Puis, tu vas te déplacer dans le dossier nouvellement créé :
> cd automate

Ensuite, tu vas créer une remote. ça te permettra de rester à jour si des modifications son faites sur le repo principal. On va appeler notre remote upstream
> git remote add upstream https://github.com/Chantesprit/automate
> git fetch upstream

Maintenant, tu devrais avoir tout tes dossiers bien à jour. A chaque fois que tu voudras te remettre à jour (si des modifs sont faites sur le repo principal), lance ça :
> git checkout master // tu te places sur ta branche principale dans ton repo local
> git fetch upstream // tu récupères les modifs faites sur le repo principal
> git merge upstream/master // et tu les appliques

Voilà, tout est prêt pour qu'on puisse bosser proprement.

Tu vas commencer par créer une nouvelle branche :
> git checkout -b <nom de ta branche>
Tu fais tous tes ajouts dans cette branche. ça permet d'avoir des modifs plus faciles à suivre après

Quand c'est fait, tu ajoutes tous les fichiers que tu as modifiés à l'index de ce qui est à commit :
> git add <tous les fichiers que tu as modifié>
> git commit -m "<un message court explicatif de ce que représente ton commit>"
> git push -u

Voilà, ton travail est maintenant sur ton github
Il va falloir que tu le proposes à la review avant qu'il soit vraiment intégré au projet principal.
Pour ça, tu vas cliquer sur le bouton vert (compare & pull request), tu vas selectionner les branches que tu viens juste de modifier et qui constituent ta modif, et tu envoies :)

Maintenant, quelqu'un d'autre va pouvoir regarder ton code, et le valider et l'intégrer au projet principal si il est bon, ou te pointer du doigt les erreurs. Il ne te reste plus qu'à les corriger sur ton repo local, de les commit, puis d'ajouter ce que tu viens de commit au pull request que tu as soumis. Et là, revérification, jusqu'à ce que ce soit bon.



Maintenant, je vais réexpliquer ce que je viens de dire, mais sans le code, en esseyant d'accer sur ce qu'on fait plutôt que sur comment on le fait.

1) On possède un repo global : Chantesprit/automate
	On ne veut pas y toucher et y faire des bêtises. Seules des modifications sûres et vérifiées devront pouvoir y être ajoutées.
	Pour celà, on va chacun le copier et faire nos modifications sur nos copies
2) Tu vas "fork" le repo global sur ton compte github. ça y'est, tu as une copie du repo global sur lequel tu peux faire des modifs sans avoir peur de faire des bêtises.
3) Tu vas créer une copie de ton repo sur github chez toi, sur ton pc, pasque c'est plus facile de bosser en local
	C'est toute la partie à base de git clone ...
4) Maintenant que tu as une copie de ton repo de github sur ta machine, tu vas pouvoir commencer à coder.
	Mais avant, il va falloir créer une branche. Une branche, c'est une séparation claire entre des versions de certaines parties de ton repo, des "versions" qui peuvent cohabiter. Donc à chaque fois que tu veux faire des modifs, tu vas crée une nouvelle branche pour pas te perdre
5) Ensuite, tu fais tes modifs sur ta branche, ton code, tes correction des erreurs des autres, etc...
6) Une fois que tu es sûr de ce que tu as fait, tu vas vouloir le mettre dans le repo global, pour faire avancer le projet.
	Pour ça, tu vas uploader les modifs que tu viens de faire et les envoyer sur ton repo github, c'est le push
7) Une fois que tu as tes modifs présentes sur ton repo github, tu vas créer ce qu'on appelle une pull request.
	ça va signifier que tu as certaines branches de ton repo personnel (branches que tu vas selectionner) que tu voudrais bien voir appliquées au repo global.
8) Va se créer un espace de discussion qui va permettre à une autre personne du repo global de vérifier ton code et de te faire des remarques si il y'a des erreurs.
9) Si ton code est exempt d'erreurs, il va être ajouté au repo global. Si il y'a des erreurs, ils faudra que tu les corriges, et que tu ajoutes ces corrections à la pull request.
10) Tu es content. Ton code fonctionne et le projet fonctionne aussi, tu peux aller boire un jus de pomme.

 