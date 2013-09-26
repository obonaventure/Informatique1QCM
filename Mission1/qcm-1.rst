.. Copyright |copy| 2013 by Olivier Bonaventure
.. raw:: html

  <script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
  <script type="text/javascript" src="js/jquery-shuffle.js"></script>
  <script type="text/javascript" src="js/rst-form.js"></script>
  <script type="text/javascript">$nmbr_prop = 4</script> 





=========================
Mission 1 : Mise en Route
=========================

Ces questions ont pour objectif de vous permettre de tester vous-m�me votre compr�hension de la mati�re couverte par cette mission de mise en route. 

Ces questions supposent que vous avez lu les sections suivantes du livre de r�f�rence |jn|_ :


 - |jn1|_

   - |jn1.1|_
   - |jn1.2|_
   - |jn1.3|_
   - |jn1.4|_
   - |jn1.5|_
   - |jn1.7|_
 
 - |jn2|_

   - |jn2.1|_
   - |jn2.2|_
   - |jn2.3|_ (sauf |jn2.3.3|_)
   - |jn2.5|_ (sauf |jn2.5.7|_)
   - |jn2.6|_ (sauf |jn2.6.3|_)

 - |jn3|_
 
   - |jn3.1|_

Question 1. Initialisation de variables
---------------------------------------

Parmi les fragments de code Java suivants, quels sont ceux qui correspondent � des initialisations correctes de variables enti�res ?


.. class:: positive

-
 .. code:: java

    int a=12;
    int b= 42352;

-
 .. code:: java

    int var1=-12;
    int var2=42352;


-
 .. code:: java

    int var1=-12;
    int var2=-var1;

 .. class:: comment

    En Java, une variable est initialis�e en utilisant une constante ou une expression qui s'�value avec le type de la variable.

-
 .. code:: java

    int var_1=-12100;
    int var_2=42352;
    

.. class:: negative

-
 .. code:: java

    int var=1;
    int ma variable=2;

 .. class:: comment

    En Java, un nom de variable ne peut jamais contenir d'espace. 


-
 .. code:: java

    int var=1.2;
    int d=2;

 .. class:: comment

    En Java, l'expression ``1.2`` est un nombre r�el et non un nombre entier. 

-
 .. code:: java

    int var1='1';
    int var2=2;

 .. class:: comment

    En Java, l'expression ``\`1\``` correspond au caract�re ``1``. Ce n'est donc pas un nombre entier. 


-
 .. code:: java

    int a=123456789123456789123456789;
    int b=2;

 .. class:: comment

    En Java, les entiers ne peuvent repr�senter que les nombres entre ``-2147483648`` et ``2147483647``. Le nombre ``123456789123456789123456789`` est trop grand. Il ne peut �tre repr�sent� que sous la forme d'un ``long``.


Question 2. Initialisation de variables
---------------------------------------

Parmi les fragments de programmes Java ci-dessous, quels sont ceux qui respectent la syntaxe du langage ?


.. class:: positive

- 
 .. code:: java

    int i=1;
    double d=2.0;
    char c='3';
    boolean b=false;
    long l=-1;


- 
 .. code:: java

    int i=0;
    double d=3.2e-1;
    char c='9';
    boolean b=true;
    long l=-1;


.. class:: negative

- 
 .. code:: java

    int i=0.9;
    double d=3.2e-1;
    char c='0';
    boolean b=false;
    long l=-1234;

 .. class:: comment
 
    Le type ``int`` ne peut �tre utilis� que pour stocker des nombres entiers.

- 
 .. code:: java

    int i=-12345;
    double d=3;
    char c='12';
    boolean b=true;
    long l=678;

 .. class:: comment

    Le type ``char`` ne peut �tre utilis� que pour stocker un (et un seul) caract�re. ``'12'`` n'est pas un caract�re valide. ``char c='2';`` serait une d�claration valide.

- 
 .. code:: java

    int i=-12345;
    double d=3;
    char c="9";
    boolean b=true;
    long l=678;

 .. class:: comment

    Le type ``char`` ne peut �tre utilis� que pour stocker un (et un seul) caract�re. En java, une expression entre guillemets comme ``"9"`` est une *cha�ne de caract�res* (un ``String``)  et non un caract�re. ``char c='9';`` (notez l'utilisation des apostrophes au lieu des guillemets) serait une d�claration valide.


- 
 .. code:: java

    int i=2/3;
    double d='8';
    char c='a';
    boolean b=false;
    long l=-1;

 .. class:: comment

    Le type ``double`` ne peut �tre utilis� que pour stocker un nombre r�el. ``'8'`` est le caract�re qui correspond au chiffre huit et non un nombre r�el. Cette initialisation n'est donc pas valide. Notez que la ligne ``int i=2/3;`` est tout � fait valide. L'initialisation d'une variable peut �tre faite en utilisant n'importe quelle expression qui retourne une variable de ce type. Cependant, comme ``i`` est une variable de type ``int``, sa valeur sera ``0`` puisque la division ``2/3`` est une division enti�re.



- 
 .. code:: java

    int i=7;
    double d=-2.34;
    char c='z';
    boolean b=0;
    long l=-1;

 .. class:: comment

    Le type ``boolean`` ne peut �tre utilis� que pour stocker une valeur bool�enne contrairement � d'autres langages tels que C. Il peut s'agir de ``true``, ``false`` ou n'importe quelle expression qui donne une valeur bool�enne. Ainsi, l'expression ``i==9`` est une expression bool�enne qui a la valeur ``false``. Cette expression aurait pu aussi �tre utilis�e pour initialiser la variable bool�enne ``b``.

Question 3. Les commentaires
----------------------------

Afin de faciliter la compr�hension des programmes �crits dans un langage de programmation tel que Java, il est important de bien le documenter en utilisant des commentaires. Parmi les fragments de code Java ci-dessous, lequel est syntaxiquement correct ?

.. class:: positive

-
 .. code:: java

   /***********************
    * Mon programme
    *
    ***********************/
    int count=7; // compteur
    int n=0;
    // test
    if(count>3) {
       n=count;
    }

-
 .. code:: java

   /***********************
    * Mon programme
    *
    ***********************/
    int count=7; // compteur
    int n=0;
    // double d;
    if(count>3) {
       n=count;
    }

 .. class:: comment

    Un ligne de commentaire est une ligne ignor�e par le compilateur Java. Certains programmeurs mettent en commentaire des lignes inutiles comme ci-dessus. Cela peut �tre utile durant l'�criture de programmes, mais �vitez de rendre un programme finalis� avec des lignes de code en commentaires.

-
 .. code:: java

   //
   // Mon programme
   //
   //
    int count=7; /* compteur */
    int n=0;
    // test
    if(count>3) {
       n=count;
    }

 .. class:: comment
  

    Ce fragment de code est correct, mais en g�n�ral on pr�f�re utiliser ``//`` et non ``/* ... */``  pour un commentaire sur une ligne. Inversement, on pr�f�re utiliser ``/* ... */`` pour un commentaire qui prend plusieurs lignes et non mettre ``//`` au d�but de chaque ligne de commentaire.

.. class:: negative

-
 .. code:: java

   /***********************
    * Mon programme
    *
    ***********************/
    int count=7; // compteur
    int n=0;
    /* test
    if(count>3) {
       n=count;
    }

 .. class:: comment
   
    Dans ce fragment de code, la ligne ``/* test`` marque le d�but d'un commentaire sur plusieurs lignes. Ce commentaire doit se terminer avec ``*/``, ce qui n'est pas le cas dans le code ci-dessus.

-
 .. code:: java

   /***********************
    * Mon programme
    *
    ***********************
    int count=7; // compteur
    int n=0;
    // test
    if(count>3) {
       n=count;
    }

 .. class:: comment

    Dans ce fragment de code, la premi�re ligne marque le d�but d'un commentaire sur plusieurs lignes. Ce commentaire doit normalement se terminer par ``*/``. Ce n'est pas le cas de l'exemple ci-dessus et le compilateur Java va consid�rer l'enti�ret� du programme comme �tant un commentaire.


-
 .. code:: java

   /***********************
    * Mon programme
    *
    ***********************
    int count=7; / compteur
    int n=0;
    / / test
    if(count>3) {
       n=count;
    }

 .. class:: comment

    Un commentaire doit d�buter par ``//`` (deux fois caract�re ``/``). Si vous utilisez un seul caract�re ``/`` ou deux caract�res ``/ /`` s�par�s par un espace, le compilateur Java ne consid�re par qu'il s'agit d'un marqueur valide de commentaire. 




Question 4. Syntaxe de Java
---------------------------


Un langage de programmation tel que Java utilise une syntaxe bien pr�cise. Il est important que vous sachiez reconna�tre rapidement des erreurs de syntaxe dans un programme Java pour �viter de les commettre vous-m�me. Les programmes ci-dessous ont �t� �crits par des �tudiants pour afficher le message ``Hello, world!`` � l'�cran. Chaque programme est stock� dans le fichier ``Hello.java``. Un seul de ces programmes est acceptable par le compilateur Java. Lequel ?


.. class:: positive

-
 .. code:: java

    public class Hello {
     
     public static void main (String[] args) {
       System.out.println("Hello, world!");
     }
    }

-
 .. code:: java

    public class Hello {
     
     public static void main (String[] args) {
       System.out.print("Hello,");
       System.out.println("world!");
     }
    }

     

.. class:: negative

-
 .. code:: java

    public class Monprog {
     
     public static void main (String[] args) {
       System.out.println("Hello, world!");
     }
    }

 .. class:: comment

    En Java, le fichier ``Hello.java`` doit toujours contenir une classe dont le nom est ``Hello``.


-
 .. code:: java

    public class hello {
     
     public static void main (String[] args) {
       System.out.println("Hello, world!");
     }
    }

 .. class:: comment

    En Java, le fichier ``Hello.java`` doit toujours contenir une classe dont le nom est ``Hello``. Les noms de classe commencent toujours par une majuscule.


-
 .. code:: java

    public class Hello {
     
     public main (String[] args) {
       System.out.println("Hello, world!");
     }
    }

 .. class:: comment

    En Java, la m�thode qui est ex�cut�e par d�faut dans une classe Java a toujours comme signature ``public static void main (String[] args)``. 


-
 .. code:: java

    public class Hello {
     
     public main (String[] args) {
       System.out.println("Hello, world!")
     }
    }

 .. class:: comment

    En Java, la ligne ``System.out.println("Hello, world!")`` doit n�cessairement se terminer par un ``;``


Question 5. Echange du contenu de variables
------------------------------------------- 

Dans un langage de programmation comme Java, il est souvent n�cessaire d'�changer le contenu de deux variables. Consid�rons le programme ci-dessous dans lequel deux variables sont initialis�es :

.. code:: java

   int a=1401;
   int b=1101;

Parmi les fragments de Java ci-dessous, lequel permet de correctement �changer le contenu de la variable ``a`` avec le contenu de la variable ``b`` ?

.. class:: negative

-  
   .. code:: java
   
      a=b;

   .. class:: comment

   Cette instruction place dans la variable ``a`` le contenu de la variable ``b`` mais pas l'inverse.

- 

  .. code:: java

     b==a;

  .. class:: comment

     Ce n'est pas une instruction valide en langage Java. Ne confondez-pas ``==`` et ``=``. 

- 

  .. code:: java

     b=a;

  .. class:: comment

     Cette instruction place dans la variable ``b`` le contenu de la variable ``a`` mais pas l'inverse.


- 
  .. code:: java


      int c; // variable d'�change
      c=b;
      a=c;
      b=a;

  .. class:: comment

     Ex�cutez pas � pas cette suite d'instructions. Que contiennent les variables ``a`` et ``b`` � la fin de cette ex�cution ? 

.. class:: positive

-

  .. code:: java

     int c; // variable d'�change
     c=a;
     a=b;
     b=c;

-

  .. code:: java

      int c; // variable d'�change
      c=b;
      b=a;
      a=c;


Question 6. Calcul du minimum
-----------------------------

Consid�rons un programme Java qui manipule deux variables : ``a`` et ``b``. Parmi les fragments de code ci-dessous, lequel place correctement dans la variable ``min`` le minimum entre les contenus de ``a`` et ``b`` ?

.. code:: java

   double a;
   double b;
   double min;

.. class:: positive

- 
   .. code:: java
 
      if(a>b)
      {
        min=b;
      }
      else
      {
        min=a;
      }


- 
   .. code:: java
 
      if(a<b)
      {
        min=a;
      }
      else
      {
        min=b;
      }


-      
   .. code:: java
   
      if(a<=b)
      {
        min=a;
      }
      else
      {
        min=b;
      }


.. class:: negative

-      
   .. code:: java
   
      if(a<=b)
      {
        double min;
	min=a;
      }
      else
      {
        double min;
        min=b;
      }
      
   .. class:: comment

      Ce code ne fonctionne pas et le probl�me est assez subtil. En red�finissant la variable ``min`` � l'int�rieur de chaque bloc, on d�finit une variable qui est consid�r�e par le compilateur comme �tant diff�rente de la variable min qui a �t� d�finie avec les variables ``a`` et ``b``. La nouvelle variable ``min`` est mise � jour � l'int�rieur du bloc mais n'est pas accessible en dehors de ce bloc.

-      
   .. code:: java
   
      if(a!=b)
      {
	min=a;
      }
      else
      {
        min=b;
      }
      
   .. class:: comment

      Ne confondez pas ``!=`` et ``<=``

-      
   .. code:: java
   
      if(a>b)
      {
	min=a;
      }
      else
      {
        min=b;
      }
      
   .. class:: comment

      Ce programme place la valeur maximale dans la variable ``min``. 

-      
   .. code:: java
   
      if(a<b)
      {
	min=a;
      }
      
   .. class:: comment

      Lorsque la valeur de la variable ``a`` est sup�rieure ou �gale � la valeur de la variable ``b``, la variable ``min`` n'est pas initialis�e. 

Question 7. Valeur absolue
--------------------------

Si ``x`` est une variable de type ``double``, lequel de ces fragments de code place dans la variable ``abs`` la valeur absolue de ``x``?

.. class:: positive

-  
 .. code:: java
    
    double abs;
    if( x<0 ) {
      abs=-x;
    }
    else {
      abs=x;
    }

-  
 .. code:: java
    
    double abs=x;
    if( x<=0 ) {
      abs=-x;
    }

-  
 .. code:: java
    
    double abs=x;
    if( x>=0 ) {
      abs=x;
    }
    else {
      abs=-x;
    }


.. class:: negative

-  
 .. code:: java
    
    double abs=x;
    if( x>=0 ) {
      abs=x;
    }

 .. class:: comment
   
    Ce fragment de code place toujours la valeur ``x`` dans la variable ``abs``.

- 
 .. code:: java

    double abs;
    if(x!=0) {
       abs=x;
    }
    else {
       abs=-x;
    }   

 .. class:: comment

    Ne confondez pas ``!=`` et ``>=``.



Question 8. Intervalles
-----------------------

En math�matiques, on d�finit des intervalles, ferm�s, ouverts et semi-ouverts. L'intervalle semi-ouvert :math:`[3,7[` comprend l'ensemble des nombres r�els qui sont sup�rieurs ou �gaux � `3` et strictement inf�rieurs � 7. Sachant que ``a``, ``b`` et ``x`` sont des variables de type ``double``, lequel des fragments de code suivants affiche ``vrai`` sur sa sortie standard si et seulement si ``x`` appartient � l'intervalle :math:`[a,b[` ? On supposera pour cette question que la valeur stock�e dans la variable ``a`` est strictement inf�rieure � celle stock�e dans la variable ``b``.

.. class:: positive

- 
 .. code:: java
 
    if(x>=a) {
      if(x<b) {
         System.out.println("vrai");
	 }
    }	 

- 
 .. code:: java
 
    if(x<b) {
      if(x>=a) {
         System.out.println("vrai");
	 }
    }	 


- 
 .. code:: java
 
    if( (x<b) && (x>=a) ){
      System.out.println("vrai");
    }


- 
 .. code:: java
 
    if( (x>=a) && (x<b) ){
      System.out.println("vrai");
    }

.. class:: negative

- 
 .. code:: java
 
    if( (a>=x) && (x<b) ) {
      System.out.println("vrai");
    }

 .. class:: comment

    Dans quels cas l'expression ``( (a>=x) && (x<b) )`` est-elle vraie ?

- 
 .. code:: java
 
    if( (a<x) && (x<b) ) {
      System.out.println("vrai");
    }

 .. class:: comment

    L'expression ``( (a<x) && (x<b) )`` est-elle vraie lorsque ``x==a`` ?

- 
 .. code:: java
 
    if( (a<=x) || (x<b) ) {
      System.out.println("vrai");
    }

 .. class:: comment

    Ne confondez pas la conjonction (`et`) logique repr�sent� par ``&&`` en Java et la disjonction (`ou`) logique repr�sent�e en Java par ``||``. 

- 
 .. code:: java
 
    if(x<a) {
      if(x<b) {
         System.out.println("vrai");
	 }
    }	 

 .. class:: comment

    Affiche-t-elle "vrai" lorsque ``x==a``?

- 
 .. code:: java
 
    if(x<=b) {
      if(x>=a) {
         System.out.println("vrai");
	 }
    }	 

 .. class:: comment

    Qu'affiche ce fragment de code lorsque ``x==b`` ?

Question 9. Op�rations arithm�tiques
------------------------------------

Un seul des fragments de programmes ci-dessous affiche "ok" � l'�cran ? Pouvez-vous trouver lequel ?

.. class:: positive

- 
 .. code:: java

    int i=2;
    int j=3;
    int k=i/j;
    if(k==0) {
       System.out.println("ok");
    }

- 
 .. code:: java

    double a=2;
    double b=3;
    double c=a/b;
    if(c!=0.0) {
       System.out.println("ok");
    }


.. class:: negative

- 
 .. code:: java

    int i=6;
    int j=7;
    int k=i/j;
    if(k!=0) {
       System.out.println("ok");
    }

 .. class:: comment

    Dans ce fragment de code, les variables sont de type ``int``. En arithm�tique enti�re, la division ``6/7`` donne comme r�sultat ``0`` avec un reste de ``6``.


- 
 .. code:: java

    double a=1;
    double b=3;
    double c=a/b;
    if(c==0.0) {
       System.out.println("ok");
    }

 .. class:: comment

    Dans ce fragment de code, les variables ``a`` et ``b`` sont de type ``double``. Elles permettent donc de stocker un nombre r�el. Le r�sultat de ``a/b`` est ``0.33333`` qui est diff�rent de ``0.0``.

- 
 .. code:: java

    int i=8;
    int j=7;
    int k=i/j;
    if(k==0) {
       System.out.println("ok");
    }

 .. class:: comment

    Dans ce fragment de code, les variables sont de type ``int``. En arithm�tique enti�re, la division ``8/7`` donne comme r�sultat ``1`` avec un reste de ``1``.

- 
 .. code:: java

    double a=6.0;
    double b=7.0;
    double c=a/b;
    if(c==0.0) {
       System.out.println("ok");
    }

 .. class:: comment

    Dans ce fragment de code, les variables ``a`` et ``b`` sont de type ``double``. Elles permettent donc de stocker un nombre r�el. Le r�sultat de ``a/b`` est diff�rent de ``0.0``.



Question 10. Boucles ``while``
------------------------------

Lequel des fragments de code Java ci-dessous permet de calculer la somme des :math:`n` premiers entiers positifs ?

.. class:: positive

-
 .. code:: java
 
    int n=...;  // >0 � initialiser correctement
    int count=0;
    int sum=0; // la somme
    while(count <n) {
       sum=sum+count;
       count=count+1;
    }
    // la variable sum contient la somme des 
    // n premiers entiers positifs

-
 .. code:: java
 
    int n=...;  // >0 � initialiser correctement
    int count=n;
    int sum=0; // la somme
    while(count>0) {
       sum=sum+count;
       count=count-1;
    }
    // la variable sum contient la somme des 
    // n premiers entiers positifs

    
.. class:: negative

-
 .. code:: java
 
    int n=...;  // >0 � initialiser correctement
    int count=0;
    int sum=0; // la somme
    while(count <n) {
       sum=sum+count;
       count=count-1;
    }
    // la variable sum contient la somme des 
    // n premiers entiers positifs

 .. class:: comment

    Cette boucle ne se termine pas.

-
 .. code:: java
 
    int n=...;  // � initialiser correctement
    int sum=0; // la somme
    while( n>1 ) {
       sum=sum+n;
       n=n-1;
    }

 .. class:: comment

    Quelle est la somme calcul�e par cette boucle ``while`` ?

-
 .. code:: java
 
    int n=...;  // � initialiser correctement
    int sum=0; // la somme
    while( sum=sum+n ) {
       n=n-1;
    }
    // la variable sum contient la somme des 
    // n premiers entiers positifs

 .. class:: comment

    L'expression qui sert de garde � une boucle ``while`` doit �tre une expression bool�enne. ``sum=sum+n`` n'est pas une expression bool�enne et ce programme n'est pas syntaxiquement valide. 

-
 .. code:: java
 
    int n=...;  // >0 � initialiser correctement
    int count=n;
    int sum=0; // la somme
    while(count>0) 
       sum=sum+count;
       count=count-1;
    // la variable sum contient la somme des 
    // n premiers entiers positifs

 .. class:: comment

    Ce programme illustre une subtilit� de l'utilisation des blocs avec le langage Java. Sans accolades, la boucle ``while`` porte uniquement sur l'instruction qui la suit. Ce code est donc �quivalent au code ci-dessous :

    .. code:: java
 
       int n=...;  // >0 � initialiser correctement
       int count=n;
       int sum=0; // la somme
       while(count>0) {
          sum=sum+count;
       }
       count=count-1;

    Dans ce fragment de code, la variable ``count`` n'est pas d�cr�ment�e dans le corps de la boucle et celle-ci ne se termine done jamais. Pour �viter ce genre de probl�mes, il est pr�f�rable de *toujours* utiliser des accolades pour d�limiter le bloc d'une boucle ``while``.
    
-
 .. code:: java
 
    int n=...;  // >0 � initialiser correctement
    int count=0;
    int sum=0; // la somme
    while(count<n) 
       sum=sum+count;
       count=count+1;
    // la variable sum contient la somme des 
    // n premiers entiers positifs

 .. class:: comment

    Ce programme illustre une subtilit� de l'utilisation des blocs avec le langage Java. Sans accolades, la boucle ``while`` porte uniquement sur l'instruction qui la suit. Ce code est donc �quivalent au code ci-dessous :

    .. code:: java
 
       int n=...;  // >0 � initialiser correctement
       int count=0;
       int sum=0; // la somme
       while(count<n) {
          sum=sum+count;
       }
       count=count+1;

    Dans ce fragment de code, la variable ``count`` n'est pas incr�ment�e dans le corps de la boucle et celle-ci ne se termine done jamais. Pour �viter ce genre de probl�mes, il est pr�f�rable de *toujours* utiliser des accolades pour d�limiter le bloc d'une boucle ``while``.

    
Question 11. Boucles ``while``
------------------------------

Les boucles ``while`` sont utiles lorsque l'on doit r�p�ter des op�rations similaires � de multiples reprises. En arithm�tique, la factorielle d'un entier positif (``n``) et sup�rieur � ``1`` est d�finie comme �tant le produit de tous les entiers inf�rieurs ou �gaux � ``n``. La factorielle de ``n`` se note :math:`n!`. Ainsi :math:`4!=24`. Parmi les boucles ``while`` ci-dessous, laquelle permet de calculer correctement :math:`n!` ?

.. class:: positive

-
 .. code:: java

    long n=17;
    long fact=1;  // factorielle
    int count=n;  // compteur pour la boucle
    while(count>1) {
       fact=fact*count;
       count=count-1;
    }

 .. code:: java

    long n=17;
    long fact=1;  // factorielle
    int count=1;  // compteur pour la boucle
    while(count<=n) {
       fact=fact*count;
       count=count+1;
    }
    

.. class:: negative

-
 .. code:: java

    long n=17;
    long fact=0;  // factorielle
    int count=n;  // compteur pour la boucle
    while(count>1) {
       fact=fact*count;
       count=count-1;
    }

 .. class:: comment

    Quel est le r�sultat de :math:`0 \times n`?

-
 .. code:: java

    long n=17;
    long fact=1;  // factorielle
    int count=1;  // compteur pour la boucle
    while(count>1) {
       fact=fact*count;
       count=count+1;
    }
    
 .. class:: comment

    Cette boucle ne s'arr�te jamais.
 
-
 .. code:: java

    long n=17;
    long fact=1;  // factorielle
    int count=n;  // compteur pour la boucle
    while(count>1) {
       fact=count;
       count=count-1;
    }
    
 .. class:: comment

    Cette boucle ne fait que placer la valeur ``count`` dans ``fact`` � chaque it�ration.

-
 .. code:: java

    long n=17;
    long fact=1;  // factorielle
    int count=1;  // compteur pour la boucle
    while(count<=n) {
       count=count+1;
       fact=fact*count;
    }
    
 .. class:: comment

    Cette boucle ne calcule pas la factorielle demand�e. Que calcule-t-elle ?

  


.. include:: ../javanotes_toc.rst
