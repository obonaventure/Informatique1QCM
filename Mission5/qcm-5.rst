.. Copyright |copy| 2013 by Olivier Bonaventure
.. raw:: html

  <link href="css/prettify.css" type="text/css" rel="stylesheet" />
  <script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
  <script type="text/javascript" src="js/jquery-shuffle.js"></script>
  <script type="text/javascript" src="js/prettify.js"></script>
  <script type="text/javascript" src="js/rst-form.js"></script>
  <script type="text/javascript">$nmbr_prop = 4</script> 



===================
Mission 5. Tableaux
===================


Ces questions supposent que vous avez lu les sections suivantes du livre de référence |jn|_ 

 - |jn2|_
 
  - |jn2.5|_

    - |jn2.5.7|_

 - |jn7|_

  - |jn7.1|_

    - |jn7.1.1|_
    - |jn7.1.2|_
    - |jn7.1.3|_ 

  - |jn7.2|_

    - |jn7.2.1|_
    - |jn7.2.3|_
    - |jn7.2.4|_ 
    - |jn7.2.6|_ 
  
  - |jn7.4|_

    - |jn7.4.1|_

  - |jn7.5|_

    - |jn7.5.1|_
    - |jn7.5.2|_
   
 - |jn8|_

  - |jn8.4|_

    - |jn8.4.1|_


Les sections vues précédemment restent bien entendu d'actualité.


Question 1. Déclaration de tableaux
-----------------------------------

Parmi les déclarations suivantes, quelle est celle qui permet de déclarer correctement un tableau dont la référence est dénommée ``tab`` et qui peut contenir 5 nombres entiers ?


.. class:: positive

- ::

    int[] tab=new int[5];

  .. class:: comment

     C'est la déclaration la plus courante pour un tableau d'entiers. Notez que cette ligne combine une déclaration (``int[] tab`` et la création du tableau correspondant permettant de stocker 5 éléments de type ``int``.

- ::
    
    int[] tab;
    tab=new int[5];

  .. class:: comment

     La première ligne déclare que ``tab`` est une référence vers un tableau d'entiers. La deuxième ligne associe cette référence à un tableau permettant de stocker 5 entiers.


.. class:: negative

- ::
  
     tab=int [5];

  .. class:: comment

     Cette ligne est incorrecte. ``tab`` n'a pas été déclaré préalablement et il faut utiliser le mot clé ``new`` pour initialiser un tableau. Relisez |jn7.1.3|_ 

- ::

     tab=new int[5];

  .. class:: comment

     Cette ligne est incorrecte. ``tab`` n'a pas été déclaré préalablement. Il faut faire précéder cette ligne d'une déclaration de ``tab``. Relisez |jn7.1.3|_ 

- ::


     int[] tab=new int[];

  .. class:: comment

     Cette ligne est incorrecte. Lorsque l'on initialise un tableau, il faut spécifier le nombre d'éléments du tableau entre [] dans le membre de droite. En Java, les tableaux ont une taille fixe qui est définie à leur création. Relisez |jn7.1.3|_ 

- ::
  
     int[5] tab=new int[];

  .. class:: comment

     Cette ligne est incorrecte. Lorsque l'on initialise un tableau, il faut spécifier le nombre d'éléments du tableau entre [] dans le membre de droite. En Java, les tableaux ont une taille fixe qui est définie à leur création. Relisez |jn7.1.3|_ 

- ::

     int tab[5]=new int[];

  .. class:: comment

     Cette ligne est incorrecte. Lorsque l'on initialise un tableau, il faut spécifier le nombre d'éléments du tableau entre [] dans le membre de droite. Relisez |jn7.1.3|_ 

     

Question 2. Initialisation de tableaux
--------------------------------------

Laquelle des lignes ci-dessous déclare un tableau contenant trois nombres réels et l'initialise avec les valeurs ``-1.0``, ``0.0`` et ``1.0``.


.. class:: positive

- ::

     double[] t=new double[] { -1.0, 0.0, 1.0};
 
  .. class:: comment

     Cette ligne est correcte. Le livre la préfère à la ligne ``double[] t= { -1.0, 0.0, 1.0};`` même si les deux sont équivalentes pour Java.

- ::

     double[] t= { -1.0, 0.0, 1.0};

  .. class:: comment

     Cette ligne est correcte. Le livre préfère la ligne ``double[] t=new double[] { -1.0, 0.0, 1.0};`` qui est plus explicite même si les deux sont équivalentes pour Java.


.. class:: negative

- ::

    double[3] t= {-1.0, 0.0, 1.0};

  .. class:: comment

    En Java, il n'existe pas de type ``double[3]`` pouvant être mis dans une déclaration. Relisez |jn7.1.3|_ 

- ::

    double t= {-1.0, 0.0, 1.0};

  .. class:: comment

    En Java, ``double t`` déclare un réel et non un tableau de réels. Relisez |jn7.1.3|_ 


- ::

    double[] t= new double[-1.0, 0.0,1.0];


  .. class:: comment

     Cette ligne n'est pas syntaxiquement correcte, relisez |jn7.1.3|_ 

- ::

    double[] t= new double{-1.0,0.0,1.0};

  .. class:: comment

     Cette ligne n'est pas syntaxiquement correcte, relisez |jn7.1.3|_ 


- ::

    double[] t= [-1.0, 0.0, 1.0];

  .. class:: comment

     Cette ligne n'est pas syntaxiquement correcte. Ne confondez pas ``{`` et ``[``. Relisez |jn7.1.3|_ 



Question 3. Initialisation de tableaux
--------------------------------------

Une fois qu'un tableau a été déclaré et initialisé, il faut parfois pouvoir connaître le nombre d'éléments se trouvant dans le tableau. Lequel des codes ci-dessous affiche-t-il le nombre d'entiers dans le tableau ``tab`` déclaré via ``int[] tab=new int[]{1,2,7,9,3,99,-12,78,119}`` ?

.. class:: positive

- ::

    System.out.println(tab.length);

.. class:: negative

- ::

    System.out.println(tab.length());

  .. class:: comment

     En Java, la syntaxe ``tab.length()`` correspond à l'exécution de la méthode ``length()`` sur l'objet dont la référence est ``tab``. Les tableaux Java ne sont pas des objets ayant des méthodes que l'on peut appeler. Relisez |jn7.1.2|_


- ::

    System.out.println(tab.size);

  .. class:: comment

     ``tab.size`` n'existe pas. Relisez |jn7.1.2|_  

- ::

    System.out.println(tab[0]);

  .. class:: comment

     ``tab[0]`` est le premier élément du tableau ``tab`` et non le nombre d'éléments présents dans le tableau. Relisez |jn7.1.2|_  

- ::

    System.out.println(tab.[length]);

 .. class:: comment

     Cette ligne est syntaxiquement incorrecte. Relisez |jn7.1.2|_  

Question 4. Tableaux à plusieurs dimensions
-------------------------------------------

Outre les tableaux à une dimension décrit dans |jn7.1|_, Java supporte également des tableaux à plusieurs dimensions. Laquelle des déclarations ci-dessous est-elle un tableau à plusieurs dimensions qui permet de stocker exactement 24 nombres entiers ?

.. class:: positive

- ::

    int[][] t=new int[4][6];
   
  .. class:: comment

     Ce tableau à deux dimensions comprend 4 lignes et 6 colonnes.
 

- ::

    int[][] t=new int[3][8];

  .. class:: comment

     Ce tableau à deux dimensions comprend 3 lignes et 8 colonnes.

.. class:: negative

- ::

    int[][] t=new int[2][4];

  .. class:: comment

     Ce tableau à deux dimensions comprend 2 lignes et 4 colonnes. Relisez |jn7.5.1|_


- ::

    int[][] t=new int[24];

  .. class:: comment

     Cette ligne est erronée. La référence déclarée à gauche est vers un tableau de tableaux alors que seul un tableau d'entiers est créé dans le membre de droite. Relisez |jn7.5.1|_

- ::

    int[] t=new int[3][8];

  .. class:: comment

     Cette ligne est erronée. La référence déclarée à gauche est vers un tableau alors qu'un tableau de tableaux d'entiers est créé dans le membre de droite. Relisez |jn7.5.1|_


- ::

    int[][] t=new int[2][4];

  .. class:: comment

     Le tableau créé a deux lignes et 4 colonnes. Il ne permet donc pas de stocker 24 nombres entiers. Relisez |jn7.5.1|_



Question 5. Tableaux ordonnés
-----------------------------

Laquelle des suites d'instructions ci-dessous est une implémentation correcte de la spécification suivante : ::

 /**
  * @pre  t est un tableau contenant au moins un élément 
  * @post retourne true si les données du tableau t sont en ordre 
  *       décroissant, false sinon
  */
  public static boolean decroissant(double[] t)
  {
    // corps à inclure
  }


.. class:: positive

- ::

    if(t.length==1) {
        return true;
    }
    for(int i=1;i<t.length;i++) {
      if (t[i-1] <= t[i]) {
            return false; 
      }
    }
    return true; 


- ::

    if(t.length==1) {
        return true;
    }
    for(int i=t.length-1;i>=1;i=i-1) {
      if (t[i-1] <= t[i]) {
            return false; 
      }
    }
    return true; 

.. class:: negative 


- ::

    if(t.length==1) {
        return true;
    }
    for(int i=0;i<t.length;i++) {
      if (t[i-1] <= t[i]) {
            return false; 
      }
    }
    return true; 

  .. class:: comment

     Que se passe-t-il lors du premier passage dans la boucle ``for`` avec un tableau ``t`` contenant ``{ 1.0, 2.0 }`` ? ``i`` vaut ``0``, quel est la valeur de ``t[0-1]`` ?

- ::

    if(t.length==1) {
        return true;
    }
    for(int i=t.length;i>=1;i=i-1) {
      if (t[i-1] <= t[i]) {
            return false; 
      }
    }
    return true; 

  .. class:: comment

     Que se passe-t-il lors du premier passage dans la boucle ``for`` avec un tableau ``t`` contenant ``{ 1.0, 2.0 }`` ? ``i`` vaut ``t.length``, quel est la valeur de ``t[i]`` ?

- ::

    if(t.length==1) {
        return true;
    }
    for(int i=1;i<t.length;i++) {
      if (t[i-1] <= t[i]) {
         return false; 
      }
      else  {
        return true;
      }
    }
    return true; 

  .. class:: comment

     Cette méthode teste-t-elle vraiment l'entièreté du tableau ? Combien de fois passe-t-elle dans la boucle ``for`` ?


- ::

    if(t.length==1) {
        return true;
    }
    for(int i=t.length-1;i>=1;i=i-1) {
      if (t[i-1] <= t[i]) {
         return false; 
      }
      else {
         return true; 
      }	  
    }
    return true; 

  .. class:: comment

     Cette méthode teste-t-elle vraiment l'entièreté du tableau ? Combien de fois passe-t-elle dans la boucle ``for`` ?

Question 6. Initialisation de tableaux à deux dimensions
--------------------------------------------------------

Considérons un tableau à deux dimensions initialisé comme suit : ::

 int[][] tab= {  { 1,2,3} ,
                 { 4,5} 
	      } ;

Laquelle des expressions booléennes ci-dessous est-elle vraie ?

.. class:: positive

- ::

     (tab[0].length==3) && (tab[1][1]==5)


- ::

     (tab.length==2) && (tab[0][2]==3)


.. class:: negative

- ::

    (tab.length==1) && (tab[1][1]==4)

  .. class:: comment

     ``tab.length`` est le nombre de lignes du tableau ``tab``, c'est-à-dire ``2``.  Relisez |jn7.5.1|_ et |jn7.5.2|_

- ::

    (tab[1].length==3) && (tab[0][1]==2)

  .. class:: comment

     ``tab[1].length`` est le nombre de colonnes de la ligne ``1`` du tableau, c'est-à-dire ``2``.  Relisez |jn7.5.1|_ et |jn7.5.2|_


- ::

    (tab[0][2]==2) && (tab[1][0]==4)

 
  .. class:: comment

     L'élément ``tab[0][2]`` a comme valeur ``3`` et non ``2``.


Question 7. Manipulation de tableau à deux dimensions 
-----------------------------------------------------

Considérons la matrice ``m`` de ``li`` lignes et ``c`` colonnes qui a été initialisée par les instructions ci-dessous : ::


   double m[][]=new double[li][c];
   int count=1;
   for(int i=0;i<li;i++) {
     for(int j=0; j<c; j++) {
         m[i][j]=count;
	 count++;
     }
   }

Laquelle des expressions booléennes ci-dessous est-elle vraie ?


.. class:: positive

- ::

     ( m[li-1][0]==((li-1)*c)+1) && (m[0][c-1]==c)

- ::

     ( m[0][0]==1) && (m[li-1][c-1]==1+li*ci)


.. class:: negative

- ::

     ( m[0][c-1]==c-1)

  .. class:: comment

     Cet élément de la matrice vaut ``c`` et car ``count`` est incrémentée à chaque passage dans la boucle ``for j<c``.

    
- ::

     ( m[li][c]==li*ci)
     

  .. class:: comment

     Il n'existe pas d'élément ``m[li][c]`` dans la matrice ``m``.

- ::

     (m[0][0]==0) && (m[0][c-1]==c)

  .. class:: comment

     ``count`` étant initialisé à ``1``, l'élément ``m[0][0]`` est initialisé à la valeur ``1``.

- ::

      ( m[0][1]==1) && (m[0][c-1]==c)


  .. class:: comment

     ``m[0][1]`` vaut ``2``



Question 8. Somme des éléments d'un tableau
-------------------------------------------

Laquelle des implémentations suivantes est-elle une implémentation correcte de la méthode ``sumTab`` dont la spécification est reprise ci-dessous : ::


  /*
   * @pre tableau contenant au moins un élément
   * @post retourne la somme des valeurs stockées dans le tableau
   */
  public static double sumTab(double[] t)


.. class:: positive


- ::

   double sum=0.0;
   for(int i=0;i<t.length;i++) {
     sum=sum+t[i];
   }
   return sum;


- ::

   double sum=0.0;
   for(int i=t.length-1;i>=0;i=i-1) {
     sum=sum+t[i];
   }
   return sum;

.. class:: negative

- ::

   double sum=0.0;
   for(int i=0;i<t.length;i++) {
    for(int j=0;j<t[i].length;j++) {
     sum=sum+t[i];
    }
   }
   return sum;

  .. class:: comment

     Ce code est utilisable pour calculer la somme des éléments d'un tableau à deux dimensions, mais le tableau ``t`` qui est passé comme paramètre effectif à la méthode est un tableau à une seule dimension. Ce code ne compilera pas dans la méthode ``sumTab``.

- ::

   double sum=0.0;
   for(int i=t.length-1;i>=0;i=i-1) {
    for(int j=0;j<t[i].length;j++) {
     sum=sum+t[i];
    }
   }
   return sum;

  .. class:: comment

     Ce code est utilisable pour calculer la somme des éléments d'un tableau à deux dimensions, mais le tableau ``t`` qui est passé comme paramètre effectif à la méthode est un tableau à une seule dimension. Ce code ne compilera pas dans la méthode ``sumTab``.


- ::

    double sum=0.0;
    for(int i=0;i<=t.length;i++) {
      sum=sum+t[i];
    }
    return sum;
 
  .. class:: comment

     Ce code provoquera une erreur à l'exécution. Il n'y a pas d'élément dans le tableau ``t`` à l'indice ``t.length``. L'indice le plus élevé du tableau est ``t.length-1``.

Question 9. Assertions
----------------------

En Java, les assertions peuvent être utilisées pour vérifier explicitement les préconditions et les postconditions d'une méthode. En programmation défensive, on utilise des ``assert`` pour vérifier explicitement les préconditions de chaque méthode. Considérons la méthode dont la spécification est reprise ci-dessous : ::
 
 /**
  * @pre a>0, b>2*a et b est pair
  * @post ....
  */
 private void methode(int a, int b)

Laquelle des séquences d'instructions ci-dessous vérifie explicitement les préconditions de cette méthode ?

.. class:: positive

- ::

    assert a>0 : "a doit être strictement positif";
    assert ( (b>2*a) && (b%2)==0 ) : "b invalide";

  .. class:: comment

     Notez qu'en Java l'expression ``(b%2)`` est une expression entière. Elle peut donc apparaître à gauche d'un signe ``==``. Il est intéressant d'utiliser des commentaires pour indiquer quelle précondition n'est pas vérifiée.
 
- ::

    assert a>0 : "a doit être strictement positif";
    assert (b>2*a) : "b trop petit";
    int reste=b%2;
    assert reste==0 : "b n'est pas pair";  

  .. class:: comment

     Il est intéressant d'utiliser des commentaires pour indiquer quelle précondition n'est pas vérifiée.  

.. class:: negative

- ::

    assert a<=0; 
    assert ( (b>2*a) && (b%2)==0 ) : "b invalide";

  .. class:: comment

     La première assertion est incorrecte. Elle est vraie lorsque ``a<=0`` or la précondition de la méthode est ``a>0``.

- ::

    int reste=b%2;
    assert a<=0 : "a doit être strictement positif";
    assert reste!=0 : "b n'est pas pair";    
    assert (b<=2*a) : "b trop petit";

  .. class:: comment

     En Java, ``assert`` permet de vérifier qu'une précondition est remplie. Si c'est le cas, l'instruction ``assert`` n'a aucun effet. Sinon, l'instruction ``assert`` affiche le message qui suit ``:`` et provoque une erreur. Lorsque l'on utilise ``assert`` pour vérifier les préconditions, on souhaite que l'exécution du programme s'arrête et que le message d'erreur soit afficher lorsqu'une précondition n'est pas vérifiée. Pour cela, l'expression booléenne contenu dans l'assertion doit être la précondition à vérifier.

- ::

    assert a<=0 : "a doit être strictement positif";
    assert ( (b<=2*a) && (b%2)!=0 ) : "b invalide";

  .. class:: comment

     Notez qu'en Java l'expression ``(b%2)`` est une expression entière. Elle peut donc apparaître à gauche d'un signe ``==``. En Java, ``assert`` permet de vérifier qu'une précondition est remplie. Si c'est le cas, l'instruction ``assert`` n'a aucun effet. Sinon, l'instruction ``assert`` affiche le message qui suit ``:`` et provoque une erreur. Lorsque l'on utilise ``assert`` pour vérifier les préconditions, on souhaite que l'exécution du programme s'arrête et que le message d'erreur soit afficher lorsqu'une précondition n'est pas vérifiée. Pour cela, l'expression booléenne contenu dans l'assertion doit être la précondition à vérifier.


Question 10. Somme de vecteurs
------------------------------

Considérons les tableaux ``a``, ``b`` et ``s`` déclarés comme indiqués ci-dessous : ::

  int[] a=new int[20];
  int[] b=new int[20];
  int[] s=new int[20];


Supposons que ces tableaux servent à stocker des vecteurs (au sens mathématique du terme). Laquelle des séquences d'instructions ci-dessous place-t-elle dans le vecteur ``s`` la somme des vecteurs ``a`` et ``b``? 

.. class:: positive

- ::

     for(int i=0; i<a.length;i++) {
      s[i]=a[i]+b[i]; 
     }

- ::

     for(int i=0; i<b.length;i++) {
      s[i]=a[i]+b[i]; 
     }

- ::

     for(int i=s.length-1; i>=0;i=i-1) {
      s[i]=a[i]+b[i]; 
     }

.. class:: negative

- ::

     s[]=a[]+b[];

  .. class:: comment

     Cette instruction est invalide en Java. Il est nécessaire d'utiliser une boucle pour calculer cette somme.

- ::

     for(int i=0; i<=a.length;i++) {
      s[i]=a[i]+b[i]; 
     }

  .. class:: comment

     Cette boucle va provoquer une erreur à l'exécution lorsque ``i`` vaut ``a.length``. Voyez-vous pourquoi ?

- ::

     for(int i=0; i<=b.length;i++) {
      s[i]=a[i]+b[i]; 
     }

  .. class:: comment

     Cette boucle va provoquer une erreur à l'exécution lorsque ``i`` vaut ``b.length``. Voyez-vous pourquoi ?

- ::

     for(int i=s.length-1; i>0;i=i-1) {
      s[i]=a[i]+b[i]; 
     }

  .. class:: comment

     Cette boucle ne calculera pas la valeur de ``s[0]``. Voyez-vous pourquoi ?


- ::

     for(int i=s.length; i>=0;i=i-1) {
      s[i]=a[i]+b[i]; 
     }

  .. class:: comment

     Cette boucle va provoquer une erreur à l'exécution lorsque ``i`` vaut ``s.length``. Voyez-vous pourquoi ?

Question 11. Tableaux de caractères
-----------------------------------

La semaine passée, vous avez écrit une méthode ``count`` permettant de déterminer le nombre d'occurences d'un caractère dans un ``String``. Lequel des corps ci-dessous est une implémentation correcte de la méthode ``isIn`` dont la spécification est ::

 /*
  * @pre chaîne s non vide
  * @post retourne true si le caractère c est présent dans la chaîne s
  *       et false sinon
  */
 public static boolean isIn(char c, char[] s)


.. class:: positive

- ::

    for(int i=0;i<s.length;i++) {
      if(s[i]==c) {
         return true;
      }
    }
    return false;

- ::

    for(int i=s.length-1;i>=0;i=i-1) {
      if(s[i]==c) {
         return true;
      }
    }
    return false;

.. class:: negative

- ::

    for(int i=0;i<s.length();i++) {
      if(s[i]==c) {
         return true;
      }
    }
    return false;

 .. class:: comment

    Le nombre d'éléments dans le tableau de caractère ``s`` est ``s.length`` et non le résultat de l'application d'une méthode ``length()`` qui ne prend pas de paramètre.


- ::

    for(int i=0;i<=s.length;i++) {
      if(s[i]==c) {
         return true;
      }
    }
    return false;

  .. class:: comment

     

- ::

    for(int i=0;i<s.length();i++) {
      if(s[i]==c) {
         return true;
      }
      else {
         return false;
      }
    }

  .. class:: comment

     Que fait cette méthode après avoir comparé ``c`` avec l'élément ``s[0]`` ?

Question 12. ``toCharArray``
----------------------------


La classe ``String`` contient une méthode baptisée `toCharArray() <http://docs.oracle.com/javase/1.5.0/docs/api/java/lang/String.html#toCharArray()>`_ qui permet de convertir un ``String`` en une chaîne de caractères. Une méthode statique équivalent pourrait avoir les spécification et signature suivantes : ::

 /* 
  * @pre chaîne s non vide
  * @post retourne un tableau de caractères ayant le même contenu que
  *       que String passé en paramètre
  */
 public static char[] toCharArray(String s)

Laquelle des séquences ci-dessous est une implémentation correcte de cette méthode ?


.. class:: positive

- ::

    char[] r=new char[s.length()];
    for(int i=0;i<s.length();i++) {
       r[i]=s.charAt(i);
    }
    return r;

  .. class:: comment
  
     Notez que la longueur d'une chaîne de caractères s'obtient en appliquant la méthode ``length()`` à une référence vers cette chaîne. La longueur du tableau de caractères ``r`` est ``r.length``.

- ::

    char[] r=new char[s.length()];
    for(int i=s.length()-1;i>=0;i=i-1) {
       r[i]=s.charAt(i);
    }
    return r;

  .. class:: comment
  
     Notez que la longueur d'une chaîne de caractères s'obtient en appliquant la méthode ``length()`` à une référence vers cette chaîne. La longueur du tableau de caractères ``r`` est ``r.length``.

.. class:: negative

- ::

   char[] r;
   for(int i=0;i<s.length();i++) {
       r[i]=s.charAt(i);
   }
   return r[];
  
  .. class:: comment

     Cette réponse contient deux erreurs. Tout d'abord, avant de pouvoir utiliser un tableau, il faut fixer sa longueur lors de son initialisation. Ensuite, pour retourner un tableau, il faut retourner une référence vers ce tableau. Si ``r`` est une référence de type ``char[]``, il suffit de 

- ::

   char[] r=s;
   return r;
  
  .. class:: comment

     En Java, ce genre de raccourci n'existe pas.

- ::

   char[] r=new char[s.length];
   for(int i=0;i<s.length;i++) {
       r[i]=s.charAt(i);
   }
   return r;

  .. class:: comment

     En Java, la longueur d'une chaîne de caractères s'obtient via ``s.length()`` et non ``s.length``.


.. include:: ../javanotes_toc.rst
