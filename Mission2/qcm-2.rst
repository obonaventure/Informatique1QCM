.. Copyright |copy| 2013 by Olivier Bonaventure
.. raw:: html

  <link href="css/prettify.css" type="text/css" rel="stylesheet" />
  <script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
  <script type="text/javascript" src="js/jquery-shuffle.js"></script>
  <script type="text/javascript" src="js/prettify.js"></script>
  <script type="text/javascript" src="js/rst-form.js"></script>
  <script type="text/javascript">$nmbr_prop = 4</script> 


============================
Mission 2. Les bases de Java
============================

Cette mission a pour objectif de renforcer vos connaissances des concepts de base de la programmation en Java. 

Ces questions supposent que vous avez lu les sections suivantes du livre de référence |jn|_ :


 - |jn2|_

     - |jn2.4|_ (sauf |jn2.4.2|_, |jn2.4.4|_, |jn2.4.5|_, et |jn2.4.6|_). 

 - |jn3|_

     - |jn3.2|_
     - |jn3.3|_ (sauf |jn3.3.3|_)
     - |jn3.4|_ (sauf |jn3.4.4|_)
     - |jn3.5|_
     
     

Question 1. Types de données primitifs
--------------------------------------

Java supporte différents types de données primitifs : ``byte``, ``int``, ``short``, ``long``, ``float``, ``double``, ``char`` et ``boolean``. Dans le cadre du cours, nous n'utiliserons pas les types ``byte`` et ``short``. Dans un programme Java, vous devez stocker les informations suivantes :

 - le nombre d'étudiants en première année (variable ``etudiants``)
 - le budget de l'état américain en dollars (variable ``budget``)
 - le nombre :math:`\pi` (variable ``pi``)
 - une mesure de température (variable ``temp``)
 - la présence d'un étudiant dans un local (variable ``present``)
 - un caractère tapé sur un clavier (variable ``caractere``)

Parmi les déclarations de variables suivantes, quelle est celle qu'il est préférable 
d'utiliser pour ces données ?

.. class:: positive

- 
  ::

     int etudiants;
     float budget;
     double pi;
     double temp;
     boolean present;
     char caractere;

-
  ::

     int etudiants;
     double budget;
     double pi;
     float temp;
     boolean present;
     char caractere;

  
.. class:: negative

- 
  ::

     double etudiants;
     double budget;
     double pi;
     double temp;
     boolean present;
     char caractere;
 
  .. class:: comment
   
     Y-a-t-il des fractions d'étudiants en première année ? Si non, pourquoi représenter ce nombre en utilisant un réel et non un entier ?

-
  ::

     int etudiants;
     double budget;
     double pi;
     float temp;
     int present;
     char caractere;
 
  .. class:: comment
   
     La présence d'un étudiant est typiquement une donnée dont la valeur peut être vraie ou fausse. C'est dans ce cas que l'on utilise un ``boolean``

- 
  ::

     int etudiants;
     long budget;
     double pi;
     float temp;
     boolean present;
     char caractere;
 
  .. class:: comment
   
     Les américains utilisent des dollars et des cents. Vous devez donc pouvoir représenter un budget de 3.45$, ce que le type ``long`` ne permet pas. 


- 
  ::

     int etudiants;
     int budget;
     double pi;
     float temp;
     boolean present;
     char caractere;
 
  .. class:: comment
   
     Les américains utilisent des dollars et des cents. Vous devez donc pouvoir représenter un budget de 3.45$, ce que le type ``int`` ne permet pas. De plus, le type ``int`` ne peut stocker que des nombres allant de ``-2147483648`` et ``2147483647``, ce qui est insuffisant pour le budget (et le déficit) américain.


Question 2. Vocabulaire
-----------------------

Considérons le fragment de programme ci-dessous.

 ::

    int i;  // ligne 1
    int j;  // ligne 2
    i=12;   // ligne 3
    j=i;    // ligne 4
    double k=0.0; // ligne 5
    if( i==j ) {  // ligne 6
       k=k+1.0;   // ligne 7
    }             // ligne 8
    else {        // ligne 9
       k=k-2.0;   // ligne 10
    }             // ligne 11

Lesquelles des affirmations ci-dessous utilisent une terminologie correcte ?


.. class:: positive

-  ``j`` est une variable de type ``int`` (entière)
   La ligne ``1`` contient une déclaration de variable
   La ligne ``3`` contient une affectation d'une valeur à une variable
   La ligne ``6`` est une instruction conditionnelle
   ``i==j`` est une expression qui a une valeur booléenne

-  ``k`` est une variable de type ``double`` (réel)
   La ligne ``1`` contient une déclaration de variable
   La ligne ``4`` contient une affectation de la valeur d'une expression (``i``) à une variable
   La ligne ``6`` est une instruction conditionnelle
   ``k+1.0`` est une expression qui a une valeur réelle

.. class:: negative

-  ``j`` est une variable de type ``double`` (réelle)
   La ligne ``1`` contient une déclaration de variable
   La ligne ``5`` contient une affectation d'une valeur à une variable
   La ligne ``6`` est une instruction conditionnelle
   ``i==j`` est une expression qui a une valeur booléenne

-  ``k`` est une variable de type ``double`` (réel)
   La ligne ``1`` contient une déclaration de variable
   La ligne ``4`` contient une affectation de la valeur d'une expression (``i``) à une variable
   La ligne ``6`` est une instruction conditionnelle
   ``k+1.0`` est une expression qui a une valeur booléenne

-  ``j`` est une variable de type ``int`` (entière)
   La ligne ``1`` contient une déclaration de variable
   La ligne ``6`` est une instruction conditionnelle
   ``i==j`` est une expression qui a une valeur entière

-  ``k`` est une variable de type ``double`` (réel)
   La ligne ``1`` contient une déclaration de variable
   La ligne ``4`` contient une affectation de la valeur d'une expression (``i``) à une variable
   La ligne ``6`` est une boucle
   ``k+1.0`` est une expression qui a une valeur réelle


Question 3. Instructions conditionnelles
----------------------------------------

Les instructions conditionnelles peuvent parfois comporter des conditions plus compliquées dans lesquelles des conditions simples sont combinées en utilisant la négation (``!``), la conjonction (``&&``) ou la disjonction logique (``||``). Parmi les instructions conditionnelles suivantes, quelle est celle dont la condition est vérifiée lorsque la valeur de la variable ``x`` se trouve dans l'intervalle :math:`[min,max[` ? On supposera que :math:`min<max`.

.. class:: positive

-
 ::

    if( (x>=min) && (x<max) ) {   }

- 
 ::

    if( (x<max) && (x>=min) ) {   }

-
 ::

    if( !(x<min) && !(x>=max) ) {   }

-
 ::

    if(! ( (x<min) && (x>=max) ) ){   }

.. class:: negative


-
 ::

    if( (x>=min) || (x<max) ) {   }

 .. class:: comment

    Ne confondez pas la conjonction logique (``&&``)  et la disjonction logique (``||``).
- 
 ::

    if( (x<max) || (x>=min) ) {   }

 .. class:: comment

    Ne confondez pas la conjonction logique (``&&``)  et la disjonction logique (``||``).

-
 ::

    if( !(x<min) || !(x>=max) ) {   }

 .. class:: comment

    Ne confondez pas la conjonction logique (``&&``)  et la disjonction logique (``||``).

-
 ::

    if(! ( (x<min) || (x>=max) ) ){   }

 .. class:: comment

    Ne confondez pas la conjonction logique (``&&``)  et la disjonction logique (``||``).


-
 ::

    if( (x<min) && (x<max) ) {   }

 .. class:: comment

    Sachant que :math:`min<max`, cette condition est équivalente à une condition plus simple.
- 
 ::

    if( (x>max) || (x>=min) ) {   }

 .. class:: comment

    Sachant que :math:`min<max`, cette condition est équivalente à une condition plus simple.

-
 ::

    if( ! ( (x>min) && (x<=max) ) ) {   }


-
 ::

    if(! ( (x<min) && (x>=max) ) ){   }

 .. class:: comment

    Ne confondez pas la conjonction logique (``&&``)  et la disjonction logique (``||``). Cette condition ne peut jamais être vraie si :math:`min<max`



Question 4. Instructions conditionnelles imbriquées
---------------------------------------------------

Dans un programme Java, il est parfois nécessaire d'avoir une instruction conditionnelle qui contient elle-même une ou plusieurs autres instructions conditionnelles. Laquelle des instructions conditionnelles suivantes affiche-t-elle le message ``ok`` à l'écran lorsque la valeur de la variable de type ``double`` ``x`` est comprise entre ``2.0`` et ``5.0`` ?

.. class:: positive

- 
 ::
 
    if (x>=2.0) {
      if (x<=5.0) {
        System.out.println("ok");
      }
    }

- 
 ::
 
    if (x<=5.0) {
      if (x>=2.0) {
        System.out.println("ok");
      }
    }


-
 ::
 
    if (x<2.0) { 
     // vide
    } else {
      if (x<=5.0) {
        System.out.println("ok");
      }
    }

 .. class:: comment

    Ce code est correct, mais il n'est pas très lisible. Mieux vaut éviter ce genre de code. Il est préférable d'écrire plutôt.

    ::
 
       if (x>=2.0) {
         if (x<=5.0) {
           System.out.println("ok");
         }
       }

.. class:: negative

- 
 ::
 
    if (x>=2.0) {
      System.out.println("ok");
    }
    
 .. class:: comment

    Ce code est incomplet.

- 
 ::
 
    if (x<=5.0) {
      System.out.println("ok");
    }

 .. class:: comment

    Ce code est incomplet.

- 
 ::
 
       if (x<2.0) {
         if (x<=5.0) {
           System.out.println("ok");
         }
       }

- 
 ::
 
       if (x>=2.0) {
         if (x>5.0) {
           System.out.println("ok");
         }
       }






Question 5. Boucles ``for``
---------------------------

Les boucles ``for`` sont très fréquemment utilisées dans des programmes Java. Vous devez pouvoir utiliser facilement de telles boucles dans vos programmes. Parmi les boucles ``for`` ci-dessous, quelle est celle qui affiche cinq fois le caractère ``*`` à l'écran ?

.. class:: positive

- 
 ::

   for(int i=0; i<5; i=i+1) {
       System.out.print("*");
   }
   System.out.println();

- 
 ::

   for(int i=5; i>0; i=i-1) {
       System.out.print("*");
   }
   System.out.println();

-
 ::

   for(double i=0.0; i<1.0; i=i+0.2) {
       System.out.print("*");
   }
   System.out.println();

-
 ::

   for(int i=10; i<=50; i=i+10) {
       System.out.print("*");
   }
   System.out.println();


.. class:: negative


- 
 ::

   for(int i=0; i<=5; i=i+1) {
       System.out.print("*");
   }
   System.out.println();

 .. class:: comment

    Cette boucle ``for`` commence à la valeur ``0`` et se termine à la valeur ``5``. Elle affiche donc six fois le caractère ``\*``.

- 
 ::

   for(int i=0; i==5; i=i+1) {
       System.out.print("*");
   }
   System.out.println();

 .. class:: comment

    Cette boucle ``for`` ne s'exécute jamais. La condition ``i==5`` n'est pas vérifiée au début de la boucle. 


- 
 ::

   for(int i=5; i>=0; i=i-1) {
       System.out.print("*");
   }
   System.out.println();

 .. class:: comment

    Cette boucle ``for`` commence à la valeur ``5`` et se termine à la valeur ``0``. Elle affiche donc six fois le caractère ``\*``.

-
 ::

   for(double i=0.0; i<1.0; i=i-0.2) {
       System.out.print("*");
   }
   System.out.println();

 .. class:: comment

    Cette boucle ne se termine jamais.

-
 ::

   for(int i=0; i<=50; i=i+10) {
       System.out.print("*");
   }
   System.out.println();

 .. class:: comment

    Cette boucle commence à la valeur ``0`` et se termine à la valeur


Question 6. Boucles ``for``
---------------------------

Laquelle des boucles ``for`` ci-dessous affiche correctement tous les diviseurs entiers du nombre ``n`` (supposé strictement positif) ?

.. class:: positive

- 
 ::

   for(int i=1; i<=n; i=i+1) {
      int reste=n%i;
      if(reste==0) {
         System.out.println(i);
      }
   }

- 
 ::

   int reste;
   for(int i=n; i>=1; i=i-1) {
      reste=n%i;
      if(reste==0) {
         System.out.println(i);
      }
   }

- 
 ::


   System.out.println(1);
   System.out.println(n);
   for(int i=2; i<n; i=i+1) {
      int reste=n%i;
      if(reste==0) {
         System.out.println(i);
      }
   }


.. class:: negative

- 
 ::

   for(int i=1; i<=n; i=i+1) {
      int reste=n%i;
      if(reste) {
         System.out.println(i);
      }
   }

 .. class:: comment

    La variable ``reste`` est de type ``int``. Elle ne peut donc pas être utilisée comme condition dans un ``if``. 


- 
 ::

   for(int i=1; i<=n; i=i+1) {
      int reste=n/i;
      if(reste==0) {
         System.out.println(i);
      }
   }

 .. class:: comment

    Ne confondez pas le reste de la division entière (symbole ``%``) avec la division entière elle-même (symbole ``/``)


- 
 ::

   int reste;
   for(int i=n; i>1; i=i-1) {
      reste=n%i;
      if(reste==0) {
         System.out.println(i);
      }
   }

 .. class:: comment

    Un nombre entier est toujours divisible par 1.

- 
 ::


   System.out.println(1);
   System.out.println(n);
   for(int i=1; i<n; i=i+1) {
      int reste=n%i;
      if(reste==0) {
         System.out.println(i);
      }
   }
 
 .. class:: comment
 
    Ce programme affiche deux fois la valeur ``1``.
 
Question 7. Boucles ``for``
---------------------------

Laquelle des boucles ``for`` ci-dessous affiche correctement les carrés des n premiers entiers positifs ?

.. class:: positive

-
 ::

    for(int i=1;i<=n;i++) {
       System.out.println(i*i);
    }

-
 ::

    for(int i=1;i<=n;i=i+1) {
       int carre=i*i;
       System.out.println(carre);
    }


.. class:: negative

-
 ::

    for(int i=1;i<=n;i++) {
       System.out.println(n*n);
    }

 .. class:: comment
 
    Qu'affiche ce programme ? La valeur de ``n`` change-t-elle durant son exécution ?

-
 ::

    for(int i=1;i<n;i=i+1) {
       int carre=i*i;
       System.out.println(carre);
    }

 .. class:: comment

    Combien de nombres sont-il affichés si la boucle démarre à ``1`` et se termine à ``n`` ?

-
 ::

    for(int i=1;i<=n;n++) {
       System.out.println(i*i);
    }

 .. class:: comment
 
    Qu'affiche ce programme ? La boucle se termine-t-elle ? 


-
 ::

    for(int i=1; i<=n*n;i++) {
       System.out.println(i);
    }

 .. class:: comment

    Combien de nombres sont affichés par ce fragment de programme. S'agit-il bien des carrés des ``n`` premiers entiers ?

Question 8. Boucles ``for`` imbriquées
--------------------------------------

Sachant que ``System.out.print("X");`` affiche le caractère ``X`` à l'écran et que ``System.out.println()`` force un retour à la ligne à l'écran, laquelle des boucles ci-dessous affiche-t-elle le carré de 4x4 ci-dessous ::

  XXXX
  XXXX
  XXXX
  XXXX

.. class:: positive

-
 ::
 
    for(int i=0;i<16;i++) {
       System.out.print("X");
       int d=i%4;
       if(d==0) {
          System.out.println();
       }
    }


-
 ::

    for(int i=0;i<4;i++) {
       for(int j=0;j<4;j++) {
          System.out.print("X");
       }
       System.out.println();
    }

-
 ::

    for(int i=1;i<=4;i++) {
       for(int j=1;j<=4;j++) {
          System.out.print("X");
       }
       System.out.println();
    }


.. class:: negative 

-
 ::
 
    for(int i=0;i<16;i++) {
       System.out.print("X");
    }

 .. class:: comment

    Ce fragment de programme affiche 16 caractères sur la même ligne, ce n'est pas ce qui est demandé.

-
 ::

    for(int i=0;i<=4;i++) {
       for(int j=0;j<=4;j++) {
          System.out.print("X");
       }
       System.out.println();
    }
 
    .. class:: comment

       Ce fragment de programme affiche 5 caractères par ligne et 5 lignes. Vérifiez les bornes de la boucle ``for``.


-
 ::

    for(int i=1;i<4;i++) {
       for(int j=1;j<4;j++) {
          System.out.print("X");
       }
       System.out.println();
    }

  .. class:: comment

     Ce fragment de programme affiche 3 caractères par ligne et 3 lignes. Vérifiez les bornes de la boucle ``for``.


Question 9. Boucles ``for`` imbriquées
--------------------------------------

Il est souvent nécessaire dans des programmes informatiques de construire des boucles imbriquées, c'est-à-dire des boucles qui contiennent elles-même d'autres boucles. Laquelle des boucles ci-dessous affiche-t-elle à l'écran le texte suivant ::

  X
  XX
  XXX
  XXXX
  XXXXX

.. class:: positive

- 
 ::

    for(int i=1;i<=5;i++) {
       for(int j=1;j<=i;j++) {
          System.out.print("X");
       }
       System.out.println();
    }


- 
 ::

    for(int i=0;i<5;i++) {
       for(int j=0;j<=i;j++) {
          System.out.print("X");
       }
       System.out.println();
    }


- 
 ::

    for(int i=0;i<5;i++) {
       for(int j=1;j<=(i+1);j++) {
          System.out.print("X");
       }
       System.out.println();
    }



.. class:: negative

- 
 ::

    for(int i=1;i<=5;i++) {
       for(int j=1;j<=i;i++) {
          System.out.print("X");
       }
       System.out.println();
    }

 .. class:: comment

    Quelle est la variable incrémentée dans la boucle imbriquée ? 

- 
 ::

    for(int i=5;i>0;i=i-1) {
       for(int j=y;j>=i;j=j-1) {
          System.out.print("X");
       }
       System.out.println();
    }

 .. class:: comment

    Ce fragment de programme affiche d'abord ``XXXXX``, ensuite ``XXXX``, ...  

- 
 ::

    for(int i=1;i<=5;i++) {
       for(int j=i;j<=5;j++) {
          System.out.print("X");
       }
       System.out.println();
    }

 .. class:: comment

    Ce fragment de programme affiche d'abord ``XXXXX``, ensuite ``XXXX``, ...  


Question 10. Boucles ``for`` et ``while``
-----------------------------------------

Java supporte à la fois les boucles ``for`` et les boucles ``while``. Souvent, on peut utiliser une boucle ``for`` à la place d'une boucle ``while`` et inversement. Considérons la boucle ``for`` ci-dessous : 

 ::
 
    for(int i=0; i<n; i=i+2) { 
       //faire quelque chose
    }

A laquelle des boucles ``while`` ci-dessous cette boucle est-elle équivalente ?

.. class:: positive

-
 ::

    int i=0;
    while(i<n) {
     // faire quelque chose
     i=i+2;
    }

-
 ::

    int i;
    i=0;
    while( !(i>=n) ) {
     // faire quelque chose
     i=i+2;
    }


.. class:: negative

-
 ::

    int i=0;
    while(i<n) {
     i=i+2;    
     // faire quelque chose
    }

 .. class:: comment

    Notez que dans ce cas, première itération de la boucle se fait avec ``2`` comme valeur pour la variable ``i``.

-
 ::

    int i=0;
    while(i!=n) {
     i=i+2;    
     // faire quelque chose
    }

 .. class:: comment

    Que se passe-t-il si la variable ``n`` est impaire ? 


-
 ::

    int i;
    i=0;
    while( !(i>=n) ) {
     i=i+2;
     // faire quelque chose
    }

 .. class:: comment

    Notez que dans ce cas, première itération de la boucle se fait avec ``2`` comme valeur pour la variable ``i``.


Question 11. Boucles imbriquées
-------------------------------

Laquelle des boucles ci-dessous permet d'afficher à l'écran un rectangle  composé de ``l`` lignes contenant chacune ``c`` caractères ? Par exemple, le rectangle ci-dessous est un rectangle de 3x7 ::

 XXXXXXX
 XXXXXXX
 XXXXXXX


On supposera pour répondre à cette question que les variables ``l`` et ``c`` ont été correctement initialisées.

.. class:: positive

-
 ::
 
    char s='X';
    for(int i=1;i<=(l*c);i++) {
       System.out.print(s);
       int reste=i%c;
       if(reste==0) {
         System.out.println();
       }
    }
    

-
 ::

    char s='X';
    for(int i=0:i<l;i=i+1) {
       for(int j=0;j<c;j=j+1) {
          System.out.print(s);
       }
       System.out.println();
    }
       

.. class:: negative

-
 ::

    char s='X';
    for(int i=0:i<c;i=i+1) {
       for(int j=0;j<l;j=j+1) {
          System.out.print(s);
       }
       System.out.println();
    }

 .. class:: comment

    Dans quel ordre les caractères ``X`` sont-ils affichés ? Le rectangle a-t-il bien ``l`` lignes et ``c`` colonnes ?

-
 ::

    char c='X';
    for(int i=0:i<l;i=i+1) {
       for(int j=0;j<c;i=i+1) {
          System.out.print(c);
       }
    } 

 .. class:: comment

    Ce programme affiche-t-il vraiment un rectangle ?    



Question 12. Calcul de la somme des diviseurs premiers d'un nombre
------------------------------------------------------------------

En arithmétique, certaines propriétés sur les nombres entiers dépendent de la somme des diviseurs entiers de ce nombre. Ainsi, un nombre :math:`n` est dit `parfait <http://fr.wikipedia.org/wiki/Nombre_parfait>`_ si :math:`\sigma(n)=2n` où :math:`\sigma(n)` est la somme des diviseurs de ce nombre. Lequel des fragments de programmes ci-dessous place dans la variable ``sigma`` la somme des diviseurs de ``n`` ?

.. class:: positive

-
 ::

    int sum=n+1;
    for(int i=2;i<n;i=i+1) {
       int reste=n%i;
       if(reste==0) {
          sum=sum+i;
       }
    }

-
 ::

    int sum=0;
    for(int i=1;i<=n;i=i+1) {
       int reste=n%i;
       if(reste==0) {
          sum=sum+i;
       }
    }


-
 ::

    int sum=0;
    for(int i=n;i>=1;i=i-1) {
       int reste=n%i;
       if(reste==0) {
          sum=sum+i;
       }
    }

.. class:: negative

-  
 ::

    int sum=0;
    for(int i=2;i<n;i=i+1) {
       int reste=n%i;
       if(reste==0) {
          sum=sum+i;
       }
    }

 .. class:: comment

    Attention à l'initialisation de la variable ``sum``. ``1`` et ``n`` sont toujours diviseurs entiers de ``n``.

-
 ::

    int sum=0;
    for(int i=1;i<=n;i=i+1) {
       int reste=n%i;
       if(reste==0) {
          sum=sum+reste;
       }
    }

 .. class:: comment

    Ce fragment de programme modifie-il la valeur de ``sum``  ?

-
 ::

    int sum=0;
    for(int i=1;i<=n;i=i+1) {
       sum=sum+i;
    }

 .. class:: comment

    Ce programme calcule la somme des entiers de ``1`` à ``n`` et non la somme des diviseurs entiers de ``n``.


-
 ::

    int sum=0;
    for(int i=1;i<=n;i=i+1) {
       int reste=n%i;
       if(reste==0) {
          sum=reste;
       }
    }

 .. class:: comment

    Ce programme calcule en fait le plus grand diviseur de ``n``. Voyez-vous pourquoi ?





.. include:: ../javanotes_toc.rst
