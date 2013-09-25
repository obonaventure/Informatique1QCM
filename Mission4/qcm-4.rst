.. Copyright |copy| 2013 by Olivier Bonaventure
.. raw:: html

  <link href="css/prettify.css" type="text/css" rel="stylesheet" />
  <script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
  <script type="text/javascript" src="js/jquery-shuffle.js"></script>
  <script type="text/javascript" src="js/prettify.js"></script>
  <script type="text/javascript" src="js/rst-form.js"></script>
  <script type="text/javascript">$nmbr_prop = 4</script> 



================================================
Mission 4. Manipulation de chaînes de caractères
================================================


Ces questions supposent que vous avez lu les sections suivantes du livre de référence |jn|_ 

 - |jn2.3|_

   - |jn2.3.1|_
   - |jn2.3.2|_
   - |jn2.3.3|_ n'est pas vu dans le cadre de ce cours

 - |jn4.7|_

   - |jn4.7.1|_
   - |jn4.7.2|_
   - |jn4.7.3|_


Les sections vues précédemment restent bien entendu d'actualité.

Question 1. Portée des variables
--------------------------------


En Java, une déclaration de variable a comme portée la zone qui sépare la déclaration de la variable de la fin du bloc dans lequel elle apparaît. Une règle de bonne pratique est de déclarer chaque variable au début du bloc de la méthode dans laquelle elle est utilisée ou dans un bloc d'une boucle par exemple. Considérons la méthode définie comme suit ::

    public static void showScope (int a, double r)
    { 
      int j;
      ... // ligne a
      for (int i = 0; ... ) {
	  double y;
	  ... // ligne c
	  if(i>0) {
	     boolean b;
	     ... // ligne e
	  }
      }
      ... // ligne f

    }


Les propositions ci-dessous sont relatives à des instructions placées à certains lignes identifiées ci-dessus. Laquelle de ces propositions est-elle correcte ?

.. class:: positive

-
 ::
 
   System.out.print(a); // ligne a
   System.out.print(r); // ligne c
   System.out.print(b); // ligne e
   System.out.print(j); // ligne f   

-
 ::
 
   System.out.print(j); // ligne a
   System.out.print(y); // ligne c
   System.out.print(b); // ligne e
   System.out.print(a); // ligne f   

.. class:: negative

-
 ::
 
   System.out.print(a); // ligne a
   System.out.print(y); // ligne c
   System.out.print(b); // ligne e
   System.out.print(i); // ligne f   

 .. class:: comment

    La variable ``i`` n'est utilisable qu'à l'intérieur de la boucle ``for``. Elle ne peut pas être utilisée en dehors de cette boucle.

-
 ::

   System.out.print(i); // ligne a
   System.out.print(y); // ligne c
   System.out.print(b); // ligne e
   System.out.print(i); // ligne f   

 .. class:: comment

    La variable ``i`` n'est utilisable qu'à l'intérieur de la boucle ``for``. Elle ne peut pas être utilisée en dehors de cette boucle.


-
 ::

   System.out.print(a); // ligne a
   System.out.print(i); // ligne c
   System.out.print(r); // ligne e
   System.out.print(y); // ligne f   

 .. class:: comment

    La variable ``y`` n'est utilisable qu'après sa déclaration dans le bloc ``for``. En dehors de ce bloc, elle ne peut pas être utilisée. 



Question 2. Portée des variables
--------------------------------

Parmi les définitions de méthodes ci-dessous, quelle est celle qui affichera correctement ``2012`` à l'écran ?


.. class:: positive

-
 ::

   public static void main(String[] args) {
   
     int i=2011;
     int b=1;
     if(b==1) {
        i=b;
     }
     else {
        i++;
     }
     System.out.println(i);

   }

 .. class:: comment

    Dans cette méthode, ``b`` vaut ``1`` et donc le bloc ``else`` est exécuté et la valeur de ``i`` est incrémentée.

-
 ::

   public static int f(int b) {
     for(int i=1;i<10;i=i+1) {
      b=b+i;
     }

     return b;
   }  

   public static void main(String[] args) {
   
     int i=2012;
     int b=1;
     b=f(i);
     System.out.println(i);

   }

 .. class:: comment 

    Notez que la variable ``i`` déclarée dans la méthode ``f`` est différente de la variable ``i`` déclarée dans la méthode ``main``.

.. class:: negative

-
 ::

   public static void main(String[] args) {
   
     int i=2012;
     int b=1;
     if(b==0) {
        int i=1;
     }
     else {
     	i=1234;
     }
     System.out.println(i);

   }

 .. class:: comment

    ``javac`` refuse de compiler ce code car on cherche à déclarer deux fois la variable ``i`` ce qui est interdit dans la même méthode.


-
 ::

   public static void main(String[] args) {
   
     int i=2012;
     int b=1;
     for(i=1; i<10; i=i+1) {
        b=b+i;
     }
     System.out.println(i);

   }

 .. class:: comment

    Cette méthode ``main`` modifie la valeur de la variable ``i`` dans la boucle ``for``. La valeur affichée est ``10``. 

-
 ::

   public static void main(String[] args) {
   
     int i=2012;
     int b=1;
     while(b!=0) {
       i=i+1;
       b=b-1;
     }
     System.out.println(i);

   }

 .. class:: comment

    Cette méthode ``main`` met à jour la variable i dans le bloc ``while``. C'est donc 2013 qui est affiché. 



-
 ::

   public static void main(String[] args) {
   
     int i=2012;
     int b=1;
     if(b!=0) {
       i=i+1;
       b=b-1;
     }
     else {
       i=2012;
     }

     System.out.println(i);

   }

 .. class:: comment

    Cette méthode ``main`` met à jour la variable i dans le bloc ``if``. C'est donc 2013 qui est affiché. 



Question 3. Surcharge de méthodes
---------------------------------


En Java, il est possible de définir plusieurs méthodes qui ont le même nom pour autant qu'elles diffèrent par le nombre ou le type de leurs arguments. La méthode ``System.out.print`` par exemple est une méthode qui existe avec comme argument un entier, un caractères, une chaîne de caractères, un booléen. Considérons les déclarations de méthodes ci-dessous :: 


 public static void affiche(char c, int i) {
  System.out.println("char, int");
 }

 public static void affiche(int i, int j) {
  System.out.println("int, int");
 }

 public static void affiche(String s, double j) {
  System.out.println("String, double");
 }

 public static void affiche(String s, boolean b) {
  System.out.println("String, boolean");
 }

Laquelle des séquences d'invocation suivantes affiche à l'écran ::

  char, int
  String, double
  int, int
  String, boolean


.. class:: positive

- 
 ::
   
   affiche('0',-4);
   affiche("abc",3.23);
   affiche(0,0);
   affiche("3.12",false);

- 
 ::
   
   affiche('c',0);
   affiche("3.12",3.23);
   affiche(-1,1);
   affiche("abc",false);


.. class:: negative

- 
 ::
   
   affiche('c',-2);
   affiche("abc",3.23);
   affiche(2,8);
   affiche("abc","true");

 .. class:: comment
 
    La dernière ligne appelle une méthode qui prend comme arguments deux ``String`` et non un ``String`` et un ``boolean``

- 
 :: 
   
   affiche('8',-2);
   affiche(3.12,3.231);
   affiche(3,-12);
   affiche("3.1",false);

 .. class:: comment

    La deuxième ligne appelle une méthode qui prend comme arguments deux ``double`` et non un ``String`` et un ``double``.

-
 ::
    
   affiche("8",-2);
   affiche("3.12",3.231);
   affiche(6,-2);
   affiche("true",false);

 .. class:: comment

    La première ligne appelle une méthode qui prend comme arguments un ``String`` et un ``int`` et non un caractère et un ``int``.


-
 ::
    
   affiche('7',0);
   affiche("3.12",3.231);
   affiche(6,"-2");
   affiche("false",true);

 .. class:: comment

    La troisième ligne appelle une méthode qui prend comme arguments un ``int`` et un ``String`` et non deux ``int``.

Question 4. Conversion de types
-------------------------------

En Java, il existe différentes solutions pour convertir un nombre réel en un nombre entier. Considérons la variable ``p`` déclarée comme suit ::


	double p=3.84;

Laquelle des instructions ci-dessous affiche-t-elle ``3`` à l'écran ?

.. class:: positive

-
 ::

 	System.out.println((int) p);

 .. class:: comment

    En Java, ``(int) p`` permet de convertir le contenu de la variable ``p`` en une valeur entière. 

.. class:: negative

-
 ::

	System.out.println(Math.round(p));

 .. class:: comment

    La méthode ``Math.round`` retourne la valeur arrondie. Dans ce cas, le résultat est ``4``. Voir http://docs.oracle.com/javase/7/docs/api/java/lang/Math.html#round(double)
-
 ::

	System.out.println(p);

 .. class:: comment

    Cette instruction affiche la valeur de ``p``, c'est-à-dire ``3.84``. 

-
 ::

	System.out.println(Math.ceil(p));

 .. class:: comment

    La méthode  ``Math.ceil`` retourne un ``double`` et non un entier. L'instruction affiche ``4.0`` à l'écran. Voir http://docs.oracle.com/javase/7/docs/api/java/lang/Math.html#ceil(double)

-
 ::

	System.out.println(Math.floor(p));

	
 .. class:: comment

    La méthode ``Math.floor`` retourne un ``double`` et non un entier. L'instruction affiche ``3.0`` à l'écran. Voir http://docs.oracle.com/javase/7/docs/api/java/lang/Math.html#floor(double)



Question 5. Conversion de types
-------------------------------

Comme décrit dans la section |jn2.5.6|_ du livre de référence, il est possible en Java de réaliser des conversions entre les nombres réels et les nombres entiers. Certaines de ces conversions sont explicites, d'autres sont implicites. Considérons le fragment de code ci-dessous ::

 double f; 
 f=...; // ligne 1
 System.out.println(f);

Lorsqu'il est exécuté, il affiche la valeur ``2.0`` à l'écran. Parmi les assignations ci-dessous, quelle est celle qui a placé la valeur ``2.0`` dans la variable ``f`` ?

.. class:: positive

-
 ::

   f=125/(40+10);

 .. class:: comment

    Dans cette expression, le dénominateur est une somme de nombres entiers, c'est donc lui-même un entier. Le numérateur est un entier également. Donc, l'opération de division est une division *entière*. Le résultat de cette division entière est ``2`` qui est automatiquement converti par Java en la valeur réelle ``2.0``.  Pour Java, cette assignation équivaut en fait à ::

     f=(double) (125/(40+10));


.. class:: negative

-
 ::
   
   f=125/(40+10.0); 

 .. class:: comment

    Dans cette assignation, Java effectue une conversion de type implicite. Le dénominateur devient automatiquement de type ``double`` et le calcul est une division de réels.  Pour Java, cette assignation équivaut en fait à ::

     f=((double) 125) / ((double) 40+10.0));
  
-
 ::

    f=125/(double) (40+10);

 .. class:: comment
  
    Dans cette assignation, le dénominateur est obligatoirement un ``double``. La division est donc une division entre nombres réels.

-
 ::

    f=125.0 / (40.0+10.0);

 .. class:: comment
  
    Dans cette assignation, le numérateur et le dénominateur sont de type ``double``. La division est donc une division entre nombres réels.


Question 6. Chaînes de caractères
---------------------------------

Considérons le code Java ci-dessous qui déclare et initialise des chaînes de caractères. ::

 String s1="abcdefghijklmnopqrstuvwxyz";

Laquelle des séquences d'instructions ci-dessous affiche-t-elle ``OK`` à l'écran ?

.. class:: positive

-
 ::

   char c=s1.charAt(5);
   if(c=='f') {
      System.out.println("OK");
   }

 .. class:: comment

    Voir http://docs.oracle.com/javase/7/docs/api/java/lang/String.html#charAt(int) pour la documentation de la méthode ``charAt``.

-
 ::

   char c=s1.charAt(0);
   if(c=='a') {
      System.out.println("OK");
   }

 .. class:: comment

    Voir http://docs.oracle.com/javase/7/docs/api/java/lang/String.html#charAt(int) pour la documentation de la méthode ``charAt``.


-
 ::

   char c=s1.charAt(s1.length()-1);
   if(c=='z') {
      System.out.println("OK");
   }

 .. class:: comment

    Voir http://docs.oracle.com/javase/7/docs/api/java/lang/String.html#charAt(int) pour la documentation de la méthode ``charAt``.


.. class:: negative


-
 ::

   char c=s1.charAt(4);
   if(c=='f') {
      System.out.println("OK");
   }

 .. class:: comment

    En Java, les caractères d'un chaîne de caractères sont numérotés à partir de l'indice ``0``. L'indice ``4`` de la chaîne de caractères ``s1`` correspond donc au caractère ``e``. Voir http://docs.oracle.com/javase/7/docs/api/java/lang/String.html#charAt(int) pour la documentation de la méthode ``charAt``.

-
 ::

   char c=s1.charAt(6);
   if(c=='f') {
      System.out.println("OK");
   }

 .. class:: comment

    En Java, les caractères d'un chaîne de caractères sont numérotés à partir de l'indice ``0``. L'indice ``6`` de la chaîne de caractères ``s1`` correspond donc au caractère ``g``. Voir http://docs.oracle.com/javase/7/docs/api/java/lang/String.html#charAt(int) pour la documentation de la méthode ``charAt``.

-
 ::

   char c=s1.charAt(1);
   if(c=='a') {
      System.out.println("OK");
   }

 .. class:: comment

    En Java, les caractères d'un chaîne de caractères sont numérotés à partir de l'indice ``0``. L'indice ``1`` de la chaîne de caractères ``s1`` correspond donc au caractère ``b``. Voir http://docs.oracle.com/javase/7/docs/api/java/lang/String.html#charAt(int) pour la documentation de la méthode ``charAt``.


-
 ::

   char c=s1.charAt(s1.length());
   if(c=='z') {
      System.out.println("OK");
   }

 .. class:: comment

    En Java, les caractères d'un chaîne de caractères sont numérotés à partir de l'indice ``0``. ``s1.length()`` est le nombre de caractères dans la chaîne ``s1``.  Le dernier caractère de cette chaîne a donc l'indice ``s1.length()-1``. Il n'y a pas de caractère à la position ``s1.length()``. Voir http://docs.oracle.com/javase/7/docs/api/java/lang/String.html#charAt(int) pour la documentation de la méthode ``charAt``. 



Question 7. Extraction de chaînes de caractères
-----------------------------------------------

Dans la classe ``String``, la méthode ``substring`` est une méthode efficace pour extraire une sous-chaîne d'une chaîne de caractères. En vous basant sur la description de ``substring`` dans le livre et dans la documentation Java http://docs.oracle.com/javase/1.5.0/docs/api/java/lang/String.html, lequel des fragments de code ci-dessous affiche-t-il la chaîne ``OK`` à l'écran ?

.. class:: positive

-
 ::

   String s1="OOOO";
   String s2="KKKK";
   String s3=s1+s2;
   System.out.println(s3.substring(3,2));


-
 ::
 
   String s1="KOKOKO";
   String s3=s1+s1;
   System.out.println(s3.substring(5,2));
 
.. class:: negative

-
 ::

   String s1="OOOO";
   String s2="KKKK";
   String s3=s1+s2;
   System.out.println(s1.substring(4,2));

 .. class:: comment

    La chaîne de caractère ``s1`` ne contient que ``OOOO``. Il n'existe pas de caractère à l'indice ``4`` dans cette chaîne.

-
 ::

   String s1="OKOKO";
   String s2="OKOKO";
   String s3=s1+s2;
   System.out.println(s3.substring(4,2));

 .. class:: comment

    La chaîne ``s3`` contient ``OKOKOOKOKO``. La chaîne de caractères extraite est donc ``OO``.




Question 8. Méthode ``indexOf``
-------------------------------

En Java, la méthode ``indexOf`` peut être utilisée pour déterminer si une chaîne de caractères est comprise dans une autre chaîne de caractères. Considérons les déclarations suivantes ::

 String s1="abcdef";
 String s2="mnopq";
 String s3="abcdefijklmnopqrstuvwxyz";

Laquelle des séquences d'instructions ci-dessous affiche ``OK`` à l'écran ?

.. class::  positive

-
 ::
 
   if(s3.indexOf(s2)>=0) {
      System.out.println("OK");
   }

-
 ::
 
   if(s3.indexOf(s1)>=0) {
      System.out.println("OK");
   }
 

.. class:: negative


-
 ::
 
   if(s1.indexOf(s2)>=0) {
      System.out.println("OK");
   }

 .. class:: comment

    Dans ce code, la méthode ``indexOf`` est appliquée à la chaîne de caractères ``s1`` et prend comme argument la chaîne de caractères ``s2``. Elle détermine donc si la chaîne ``s2`` est une sous-chaîne de ``s1``. Comme ce n'est pas le cas, elle retourne donc ``-1``.

-
 ::
 
   if(s2.indexOf(s3)>=0) {
      System.out.println("OK");
   }

 .. class:: comment

    Dans ce code, la méthode ``indexOf`` est appliquée à la chaîne de caractères ``s2`` et prend comme argument la chaîne de caractères ``s3``. Elle détermine donc si la chaîne ``s3`` est une sous-chaîne de ``s2``. Comme ce n'est pas le cas, elle retourne donc ``-1``.


-
 ::
 
   if(s2.indexOf(s3)>=0) {
      System.out.println("OK");
   }


 .. class:: comment

    Dans ce code, la méthode ``indexOf`` est appliquée à la chaîne de caractères ``s2`` et prend comme argument la chaîne de caractères ``s3``. Elle détermine donc si la chaîne ``s3`` est une sous-chaîne de ``s2``. Comme ce n'est pas le cas, elle retourne donc ``-1``.




Question 9. Méthodes de la classe ``String``
--------------------------------------------

La classe ``String`` contient de nombreuses méthodes utiles de manipulation des chaînes de caractères. Certains retournent un booléen, d'autres retournent un caractère, d'autres encore retourne un ``String``. En considérant les déclarations ci-dessous, quelle est la suite d'affirmations ci-dessous qui est vraie ? ::

 String s1="abcdef";
 String s2="mnopq";
 String s3="abcdefijklmnopqrstuvwxyz";

.. class:: positive

 - ``s1.equalsIgnoreCase(s2)`` est un booléen, ``s1.charAt(2)`` est un caractère et ``s3.indexOf(s2)`` est un entier

 - ``s1.equalsIgnoreCase(s2)`` est un booléen, ``s2.length()`` est un entier et ``s1.substring(1,2)`` est une chaîne de caractères

.. class:: negative

 - ``s2.equalsIgnoreCase(s3)`` est un booléen, ``s3.length()`` est un caractère et ``s2.indexOf(s3)`` est un entier

 .. class:: comment

    La méthode ``length`` retourne la longueur de la chaîne de caractère sur laquelle elle s'applique. Cette valeur est un entier.

 - ``s2.equalsIgnoreCase(s2)`` est un booléen, ``s3.indexOf(s2)`` est un caractère et ``s2.substring(1,2)`` une chaîne de caractères

 .. class:: comment

     La méthode ``indexOf`` retourne un entier et non un caractère.

 - ``s1.equalsIgnoreCase(s2)`` affiche ``true`` ou ``false``, ``s3.indexOf(s2)`` est entier et ``s2.substring(1,2)`` une chaîne de caractères

 .. class:: comment

    La méthode ``equalsIgnoreCase`` retourne un booléen, elle n'affiche rien.


Question 10. Méthode ``contains``
---------------------------------


Laquelle des implémentations de la méthode ``contains`` dont la spécification et la signature sont reprises ci-dessous est-elle valide ? ::

 /*
  * @pre s non vide
  * @post retourne true si le caractère c est présent dans la chaîne s et false sinon
  */

 public static boolean contains(String s, char c)

.. class:: positive

-
 ::

   {
    for(int i=0;i<s.length();i=i+1) {
      if(s.charAt(i)==c) {
         return true;
      }
    }
    return false;
   }


-
 ::

   {
    for(int j=s.length()-1;j>=0;j=j-1) {
      if(s.charAt(j)!=c) {
         return true;
      }
    }
    return false;
   }

.. class:: negative


-
 ::

   {
    for(int i=0;i<s.length();i=i+1) {
      if(s.charAt(i)!=c) {
         return false;
      }
    }
    return true;
   }

 .. class:: comment

    Cette méthode retourne ``false`` dès qu'un caractère diffère du caractère passé en argument, mais elle ne teste pas toute la chaîne de caractères. 

-
 ::

   {
    for(int j=s.length();j>=0;j=j-1) {
      if(s.charAt(j)==c) {
         return true;
      }
    }
    return false;
   }

 .. class:: comment

    Cette méthode commence par essayer d'accéder au caractère à l'indice ``s.length()``, mais celui-ci n'existe pas puisque les indices des caractères d'une chaînes démarrent à ``0``.


-
 ::

   {
    for(int j=s.length()-1;j>0;j=j-1) {
      if(s.charAt(j)==c) {
         return true;
      }
    }
    return false;
   }

 .. class:: comment

    Cette méthode ne teste pas le caractère se trouvant à l'indice ``0`` de la chaîne de caractères ``s``. Elle ne fonctionne donc pas dans tous les cas.
    
-
 ::

   {
    for(int i=0;i<=s.length();i=i+1) {
      if(s.charAt(i)==c) {
         return true;
      }
    }
    return false;
   }

 .. class:: comment

    Cette méthode essaye de tester le caractère à l'indice ``s.length()`` de la chaîne de caractères, mais ce caractère n'existe pas. Cela provoquera une erreur à l'exécution.


-
 ::

   {
    for(int i=0;i<s.length();i=i+1) {
      if(s.charAt(i)==c) {
         return true;
      }
      else {
         return false;
      }
    }

   }

 .. class:: comment

    Cette méthode teste uniquement la valeur du premier caractère. Voyez-vous pourquoi ? 





.. include:: ../javanotes_toc.rst
