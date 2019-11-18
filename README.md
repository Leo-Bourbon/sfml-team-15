# SFML Team 15

The Lone Explorer est un jeu d’action-aventure “rogue like” en 2D vue du dessus.
Le joueur contrôle un personnage et doit explorer un donjon consistant en un ensemble de salles rectangulaires, organisées par étages.
Le personnage qu'incarne le joueur se bat et se déplace dans les quatre directions de l'espace : haut, bas, gauche et droite.
Des ennemis s'opposent à la progression du personnage, et oblige le joueur à alterner entre des phases de combat à l'arc, et des phases de recherche.

Un étage est divisé en 6 à 8 salles.
Les salles, nommées de A à J, sont déjà créés à l’avance. Seulement leur agencement est aléatoire.
Le joueur commence dans la salle de départ.
De plus, il existe 2 salles spéciales :
-Une salle avec un objet, qui peut donner plus de vie ou plus de dégâts
-Une salle avec un boss, qui consiste en un ennemi plus résistant.

Une fois le boss éliminé, les salles qui constituent l’étage ainsi que leur agencement est tiré à nouveau aléatoirement. 
Le personnage est replacé dans la salle de départ. C’est donc ainsi le “deuxième” étage.

Lorsque des salles contiennent des ennemis, le joueur doit les éliminer afin de pouvoir emprunter les portes.
Lorsque le personnage atteint n'importe laquelle des portes de l'écran, un effet de transition fait disparaître la salle en cours et affiche la salle adjacente à cette porte la.
