# Encodage et Décodage d'une image(Raté)  
    
  Le but ici étant de prendre une image et de modifier la couleur des pixels de manière
  à la rendre inidentifiable. Le processus inverse sera appliqué pour rendre l'image
  de nouveau identifiable.

  ## Librairie utilisée  
  **Numpy**:  
  `  import numpy as np  `  
  utile pour gérer des listes.  
  **Pillow**:  
  `  from PIL import Image  `  
    utile pour récupérer les données, les pixels, les dimensions des images et les afficher.  
     
  ## Résultats:  
      
  Comme on peut le voir au niveau des 3 fichiers jpeg, aucun n'est semblable à un autre.
  Le `Input.jpeg` ètant l'image originel, une fois encodée en sortie nous avons le `output_enc.jpeg`.
  Jusque là il n'y a pas de problème, l'image n'est pas identifiable la moitié du travail est fait(Youpii!!!).  
  Au moment du décodage on n'est sensé retrouvé l'image de base sauf que ce n'est pas le cas, sur le `output_dec.jpeg`  
  on peut apercevoir des couleurs présentes dans le `Input.jpeg` mais les images ne sont pas les mêmes.
  De plus si on compare la liste des pixels des 2 images, on peut voir qu'elles sont identiques!
  Donc d'où vient le problème? Je ne sais pas.

