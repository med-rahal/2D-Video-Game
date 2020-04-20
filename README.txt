
						***Definition et utilisation MINMAX***

Minimax est une sorte d'algorithme de retour en arrière qui est utilisé dans la prise de décision et la théorie des jeux pour trouver le 

mouvement optimal pour un joueur, en supposant que votre adversaire joue également de manière optimale. Il est largement utilisé dans les jeux 

au tour par tour à deux joueurs tels que Tic-Tac-Toe, Backgammon, Mancala, Chess, etc.


Dans Minimax, les deux joueurs sont appelés maximiseur et minimiseur. Le maximiseur essaie d'obtenir le score le plus élevé possible tandis 

que le minimiseur essaie de faire le contraire et d'obtenir le score le plus bas possible.


Chaque état de la carte a une valeur qui lui est associée. Dans un état donné, si le maximiseur a le dessus, le score du plateau aura tendance 

à être une valeur positive. Si le minimiseur a le dessus dans cet état de carte, il aura tendance à avoir une valeur négative. Les valeurs du 


plateau sont calculées par des heuristiques uniques à chaque type de jeu.



 
  							***PSUEDOCODE***



			function minimax(node, depth, maximizingPlayer) is
    				if depth = 0 or node is a terminal node then
       				 return the heuristic value of node
    				if maximizingPlayer then
       				 value := −∞
       				 for each child of node do
          			  value := max(value, minimax(child, depth − 1, FALSE))
       				   return value
    				else (* minimizing player *)
    	  				  value := +∞
       				 for each child of node do
         		  	  value := min(value, minimax(child, depth − 1, TRUE))
       					 return value
