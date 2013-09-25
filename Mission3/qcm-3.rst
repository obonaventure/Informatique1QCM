.. Copyright |copy| 2013 by Olivier Bonaventure
.. raw:: html

  <link href="css/prettify.css" type="text/css" rel="stylesheet" />
  <script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
  <script type="text/javascript" src="js/jquery-shuffle.js"></script>
  <script type="text/javascript" src="js/prettify.js"></script>
  <script type="text/javascript" src="js/rst-form.js"></script>
  <script type="text/javascript">$nmbr_prop = 4</script> 



====================================
Mission 3. Méthodes et sous-routines
====================================

Ces questions supposent que vous avez lu les sections suivantes du livre de référence |jn|_ 

 - |jn4|_
 
    - |jn4.1|_
    - |jn4.2|_
	
	- |jn4.2.1|_
	- |jn4.2.2|_
	- |jn4.2.3|_
	- |jn4.2.4|_
 
    - |jn4.3|_

        - |jn4.3.1|_
        - |jn4.3.2|_
        - |jn4.3.3|_
        - |jn4.3.4|_ 
        - |jn4.3.6|_
	 
    - |jn4.4|_

        - |jn4.4.1|_
        - |jn4.4.2|_
        - |jn4.4.3|_

    - |jn4.6|_

	- |jn4.6.1|_



Question 1. Appel de méthodes de la classe ``Math``
---------------------------------------------------

La classe ``Math``, décrite dans la section |jn2.3.1|_ du livre contient différentes méthodes de calcul. Celles-ci sont définies plus en détails dans http://docs.oracle.com/javase/6/docs/api/java/lang/Math.html. Parmi les fragments de programme ci-dessous, quels sont ceux qui sont corrects : 

.. class:: positive

-
 ::
 
    int i=1;
    int j=-1;
    double d=2.0;
    double e=3.0;
    int k=Math.abs(j);
    double f=Math.exp(d);
    double r=Math.rint(e);
    double w=Math.random();

-
 ::
 
    int i=1;
    int j=-1;
    double d=2.0;
    double e=3.0;
    int k=Math.abs(d);
    double f=Math.exp(e);
    double r=Math.rint(d);
    double x=Math.random();

.. class:: negative

-
 ::
 
    int i=1;
    int j=-1;
    double d=2.0;
    double e=3.0;
    int k=Math.abs(j);
    double f=Math.exp(e);
    int r=Math.rint(d);
    double w=Math.random();

 .. class:: comment

    La méthode ``Math.rint`` prend comme argument un réel et retourne un réel (même si celui-ci a une valeur entière). Ceci vous est indiqué par le type retourné par la méthode ``Math.rint`` dans la documentation.

-
 ::
 
    int i=1;
    int j=-1;
    double d=2.0;
    double e=3.0;
    int k=Math.abs(j);
    double f=Math.exp(i);
    double r=Math.rint(e);
    double w=Math.random();

 .. class:: comment

    La méthode ``Math.exp`` prend comme argument un réel. 



-
 ::
 
    int i=1;
    int j=-1;
    double d=2.0;
    double e=3.0;
    int k=Math.abs(j);
    double f=Math.exp(d);
    double r=Math.rint(e);
    int w=Math.random();

 .. class:: comment

    La méthode ``Math.random`` retourne toujours une valeur de type ``double``.
    

-
 ::
 
    int i=1;
    int j=-1;
    double d=2.0;
    double e=3.0;
    int k=Math.abs(i);
    double h=Math.exp(e);
    double r=Math.rint(d);
    Math.random();

 .. class:: comment

    La méthode ``Math.random`` retourne toujours une valeur de type ``double``. Elle ne peut donc jamais être utilisée comme une méthode ``void``.
    

Question 2. Utilisation de méthodes
-----------------------------------

Un étudiant écrit dans un programme Java le code suivant :

 ::

    double d=123.45;
    int i=12;
    if( f(d,i) ) { ... }

Quelle doit être la déclaration de la méthode ``f`` pour que ce fragment de programme soit valide ?

.. class:: positive

- 
 ::

    public static boolean f( double d, int i) { 
     // code non fourni
    }

- 
 ::

    public static boolean f( double a, int b) {
     // code non fourni
    }


.. class:: negative

- 
 ::

    public static int f( int a, int b) { 
     // code non fourni
    }


 .. class:: comment

    Pour pouvoir être utilisée dans une condition, la méthode ``f`` doit retourner une valeur de type ``boolean``. La déclaration ci-dessus retourne une valeur de type ``int``. En outre, le premier argument de la méthode ``f`` est un ``int`` alors que l'étudiant passe un ``double``.

- 
 ::

    public static double f( double x, double y) { 
     // code non fourni
    }

 .. class:: comment

    Pour pouvoir être utilisée dans une condition, la méthode ``f`` doit retourner une valeur de type ``boolean``. La déclaration ci-dessus retourne une valeur de type ``double``. En outre, le second argument de la méthode ``f`` est un ``double`` alors que l'étudiant passe un ``int``.



   
Question 3. Méthodes permettant d'afficher
------------------------------------------

Un étudiant souhaite une méthode ``affiche`` permettant d'afficher ``n`` fois le caractère ``X`` à l'écran. La spécification de cette méthode est ::

 /*
  * @pre n>0
  * @post affiche n fois le caractère 'X' sur une ligne
  */


Il souhaite pouvoir utiliser cette méthode de la façon suivante :

 ::

    int n=17;
    affiche(n);

Lors de son exécution, cette méthode affiche à l'écran ::

    XXXXXXXXXXXXXXXXX

Parmi les méthodes définies ci-dessous, laquelle est une implémentation (signature et corps) correct de cette méthode ``affiche`` ?


.. class:: positive

- 
 ::

    public static void affiche(int n) {
       for (int i=0;i<n;i=i+1) {
           System.out.print('X');
       }
       System.out.println();
    }

- 
 ::

    public static void affiche(int n) {
       for (int i=1;i<=n;i=i+1) {
           System.out.print('X');
       }
       System.out.println();
    }

- 
 ::

    public static void affiche(int n) {
       for (int i=n;i>0;i=i-1) {
           System.out.print('X');
       }
       System.out.println();
    }


.. class:: negative

- 
 ::

    public static int affiche(int nombre) {
       for (int j=0;j<nombre;j++) {
           System.out.print('X');
       }
       System.out.println();
    }

 .. class:: comment

    Cette méthode ne se compile pas. Elle est déclarée comme retournant un ``int`` et ne contient pas d'instruction ``return``.
    
- 
 ::

    public static void affiche( nombre) {
       for (int j=0;j<nombre;j++) {
           System.out.print('X');
       }
       System.out.println();
    }

 .. class:: comment

    Cette méthode ne se compile pas. Le type de son premier argument n'est pas spécifié. 
    

- 
 ::

    public static void affiche(int n) {
       for (int i=1;i<=n;) {
           System.out.print('X');
       }
       System.out.println();
    }

 .. class:: comment

    Ce méthode boucle indéfiniment. Pouvez-vous voir pourquoi ?

- 
 ::

    public static int affiche(int n) {
       for (int i=n;;i--) {
           System.out.print('X');
       }
       System.out.println();
    }

 .. class:: comment

    Cette méthode boucle indéfiniment. Pouvez-vous voir pourquoi ?


Question 4. Méthodes ``void``
-----------------------------

En Java, les méthodes de type ``void`` sont souvent utilisées lorsqu'il faut exécuter une suite d'instructions qui ne doit pas retourner de valeur. On souhaite écrire une méthode ``afficheSomme`` qui affiche à l'écran la somme entre deux nombres entiers. Par exemple, en exécutant ``afficheSomme(3,4)``, la valeur ``7`` est affichée à l'écran. La spécification de cette méthode est ::

 /*
  * @pre -
  * @post Affiche à l'écran la somme des deux entiers passés en arguments
  */

.. class:: positive

- 
 ::
 
    public static void afficheSomme(int a, int b) 
    {
       int somme=a+b;
       System.out.println(somme);
    }

- 
 ::
 
    public static void afficheSomme(int x, int y) 
    {
       System.out.println(x+y);
    }
 
 .. class:: comment

     L'expression ``x+y`` est une expression qui a comme valeur un entier. Elle peut donc bien être utilisée comme argument de la méthode ``System.out.println()``.

.. class:: negative

- 
 ::
 
    public static void afficheSomme(a, b) 
    {
       int s=a+b;
       System.out.println(s);
    }

 .. class:: comment

    Lors de la déclaration d'une méthode, il est nécessaire de spécifier le type de chacun de ses arguments. Cette déclaration n'est pas valide.
-
 ::
 
    public static void afficheSomme(int c, int d) 
    {
       int sum=c+d;
    }

 .. class:: comment

    Cette méthode calcule la somme de ses deux arguments mais ne l'affiche pas à l'écran comme demandé.

- 
 ::
 
    public static void afficheSomme(double c, double d) 
    {
       System.out.println(x+y);
    }

 .. class:: comment

    Cette méthode prend comme arguments deux nombres réels et non deux entiers comme demandé dans l'énoncé.


Question 5. Déclarations de méthodes
------------------------------------

En Java, la déclaration d'une méthode nous renseigne sur le type de valeur qui est retourné par cette méthode. Considérons les définitions de méthodes ci-dessous.

::

   public static void v(int i)  {
     // code non fourni
   }
   public static void w()  {
     // code non fourni
   }
   public static int f(int i)  {
     // code non fourni
   }
   public static int g(boolean b)  {
     // code non fourni
   }
   public static int h()  {
     // code non fourni
   }

Une seule des séquences d'instructions ci-dessous est valide. Pourriez-vous indiquer laquelle ?


.. class:: positive

-
 ::

    int a=f(2);
    int b=g(false);
    int c=h();
    w();
    
- 
 ::

    int a=g(true); 
    int b=f(-2);
    int c=h();
    v(a);

- 
 ::

    int a=g(false); 
    int b=f(a-2);
    int c=h();
    v(a);


 .. class:: comment

    Ce fragment de code est valide. Notez que l'argument de la méthode ``f`` peut être n'importe quelle expression qui retourne une valeur de type ``int``. C'est bien le cas pour l'expression ``a-2`` puisque la variable ``a`` est de type ``int``.

-
 ::

    int b=f(-2);
    int a=g(b==1); 
    int c=h();
    v(a);

 .. class:: comment

    Ce fragment de code est valide. Notez que l'argument de la méthode ``g`` peut être n'importe quelle expression qui retourne une valeur de type ``boolean``. C'est bien le cas pour l'expression ``b==1``.

.. class:: negative 

-
 ::

    int a=g(false); 
    int b=f(-2);
    int c=w();
    h();
    
 .. class:: comment

    Ce fragment de code contient deux erreurs. Relisez la définition des méthodes ``h`` et ``w``. La première (``h``) retourne une valeur entière. Elle ne peut donc être utilisée que dans une expression qui donne un résultat entier.  La seconde (``w``) est de type ``void``, elle ne retourne donc aucune valeur et ne peut pas être utilisée comme membre de droite d'une instruction d'affectation.
  
-
 ::

    int a=g(false); 
    int b=f(-2.0);
    int d=h();
    v(d); 

 .. class:: comment

    Quel est le type de la valeur ``2.0`` en Java ? La méthode ``f`` prend un argument de type `ìnt``.


- 
 ::

    int a=g(1); 
    int b=f(7);
    int c=h();
    w(); 


Question 6. Méthodes retournant un nombre
-----------------------------------------


La classe ``Math`` de java contient la méthode ``Math.min``. Celle-ci prend deux arguments de type ``double`` et retourne le plus petit des deux nombres passés en argument. 
Laquelle de ces méthodes reprises ci-dessous est-elle une implémentation correcte de cette méthode ``min`` dont la spécification est ::

 /*
  * @pre -
  * @post retourne le minimum entre les deux arguments
  */

.. class:: positive

- 
 ::

    public static double min (double a, double b) {
      if (a<b) {
          return a;
      }
      return b;
    }

  .. class:: comment

     Cette implémentation est correct. Lorsque ``a<b``, la méthode se termine par ``return a;``. L'instruction ``return b;`` n'est exécutée que si ``b>=a``.
    

- 
 ::

    public static double min (double a, double b) {
      if (a<b) {
          return a;
      } 
      else {
          return b;
      }
    }

- 
 ::

    public static double min (double a, double b) {
      if (b<a) {
          return b;
      } 
      else {
          return a;
      }
    }

.. class:: negative

-
 ::

    public static double min (double a, double b) {
      if (b<a) {
          System.out.println(b);
      } 
      else {
          System.out.println(a);
      }
    }

 .. class:: comment

    Ne confondez pas une méthode qui "affiche" (en utilisant ``System.out.println``) avec une méthode qui retourne une valeur. Un méthode qui retourne une valeur doit toujours se termine par ``return``. ``javac`` n'acceptera pas de compiler cette méthode qui ne retourne pas de valeur.

-
 ::

    public static double min (double a, double b) {
      if (b<a) {
          return b;
      } 
    }
  
 .. class:: comment

    Cette méthode ne se compile pas. En Java, une méthode ``double`` doit toujours retourner, via l'instruction ``return``, une valeur de type ``double``, quel que soit l'exécution de cette méthode. Cette version ne retourne de valeur que lorsque ``b<a``. 

-
 ::

    public static void min (double a, double b) {
      if (b<a) {
          return b;
      } 
      return a;
    }
    
 .. class:: comment

    Une méthode ``void`` ne retourne aucun résultat. Ce code ne correspond pas à ce qui est demandé.


Question 7. Méthodes retournant un booléen
------------------------------------------


Lorsque l'on doit manipuler des conditions complexes dans une instruction conditionnelle ou une boucle, il peut être intéressant d'écrire des méthodes qui retournent un booléen. Sachant que l'expression ``a%b`` retourne le reste de la division euclidienne de la valeur de la variable entière ``a`` par ``b``, laquelle des méthodes ci-dessous est-elle une implémentation de la spécification suivante ::

 /*
  * @pre n>0
  * @post retourne true lorsque le nombre passé en argument est pair et false dans le cas contraire
  */

.. class:: positive

-
 ::

    public static boolean pair(int n) {
      int reste=n%2;
      return (reste==0);
    }     

-
 ::

    public static boolean pair(int n) {
      int reste=n%2;
      boolean pair=(reste==0);
      return pair;
    }     

-
 ::

    public static boolean pair(int n) {
      int reste=n%2;
      if (reste!=0) {
          return false;
      }
      else {
          return true;
      }
    }

 .. class:: comment

    Ce code est correct, mais il est inutilement long. Sachant que l'instruction conditionnelle évalue une condition qui a déjà une valeur booléenne, il est préférable de retourner directement une telle expression. Comme dans le code ci-dessous ::

       public static boolean pair(int n) {
        int reste=n%2;
        return (reste==0);
       }    


.. class:: negative

-
 ::

    public static boolean pair(int n) {
      int reste=n%2;
      return (reste!=0);
    }     

 .. class:: comment

    Cette méthode retourne ``true`` lorsque x est impair et ``false`` sinon.

-
 ::

    public static boolean pair(double n) {
      int reste=n%2;
      return (reste=0);
    }     

 .. class:: comment

    L'argument de la méthode doit nécessairement être de type ``int`` pour pouvoir utiliser le reste de la division euclidienne. En outre, ``reste=0`` est une affectation et non une expression booléenne que l'on peut passer comme argument à ``return``.

-
 ::

    public static boolean pair(int n) {
      int reste=n%2;
      return reste;
    }     

 .. class:: comment

    Ce fragment de code est incorrect. La définition de la méthode spécifie qu'elle retourne une valeur booléenne. Or, ``reste`` est une variable de type ``int``. 


-
 ::

    public static boolean pair(int n) {
      int reste=n%2;
      if (reste!=0) {
          return false;
      }
    }

 .. class:: comment

    Cette méthode ne se compile pas. Elle ne définit pas correctement la valeur qu'il faut retourner lorsque ``reste==0``. 


Question 8. Calcul du maximum
-----------------------------

La classe ``Math`` contient de nombreuses méthodes. Vous trouverez notamment la méthode ``Math.max(double a, double b)`` qui calcule le maximum entre les deux nombres passés en argument. Laquelle des méthodes ci-dessous est-elle une implémentation de la spécification suivante ::

 /*
  * @pre -
  * @post retourne le maxium entre les deux réels passés en arguments
  */



.. class:: positive

-
 ::

    public static double max(double a, double b)
    {
      if(a>b) {
         return a;
      }
      else
      {
         return b;
      }
    }

- 
 ::

    public static double max(double a, double b)
    {
      if(a<=b) {
         return b;
      }
      else
      {
         return a;
      }
    }

- 
 ::

    public static double max(double a, double b)
    {
      if(a<=b) {
         return b;
      }
      return a;
    }

 .. class:: comment

    Ce code est correct. Il est cependant un peu moins lisible qu'un programme dans lequel ``return a;`` se trouverait à l'intérieur d'un bloc ``else``.

 
    
.. class:: negative

-
 ::

    public static double max(double a, double b)
    {
      if(a>b) {
         return a;
      }
      else
      {
         return a;
      }
    }

 .. class:: comment

    Ce code retourne toujours la même valeur.

-
 ::

    public static double max(double a, double b)
    {
         return a;
    }

 .. class:: comment

    Ce code retourne toujours la même valeur.


- 
 ::

    public static double max(double a, double b)
    {
      if(a>=b) {
         return a;
      }
    }

 .. class:: comment

    Ce code ne compile pas. La méthode ``max`` proposée ne retourne pas de valeur lorsque ``a<b``.

- 
 ::

    public static double max(double a, double b)
    {
      if(a>=b) {
         return b;
      }
      return a;
    }

 .. class:: comment

    Ce code retourne en fait le ``minimum`` entre les nombres ``a`` et ``b`` passés en arguments.


Question 9. Calcul de la valeur absolue
---------------------------------------


Dans le programme Java suivant, un étudiant souhaite utiliser une méthode ``abs`` permettant de calculer la valeur absolue d'un nombre.

 ::
     
    int i=1401;
    double d=-112.4;
    double j=d+abs(2*d);


.. class:: positive

-
 ::

    public static double abs(double c) {
       double r=c;
       if(c<0) {
         r=-c;
       }
       return r;
    }

-
 ::

    public static double abs(double c) {
       if(c>=0) {
         return c;
       }
       return (-c);
    }

	 
.. class:: negative

-
 ::

    public static int abs(double c) {
       if(c<0) {
         return (-c);
       }
       return c;
    }

 .. class:: comment

    Le code utilisé par l'étudiant s'attend à recevoir un ``double``. La méthode doit également retourner un ``double`` et non un ``int`` comme ci-dessus.
-
 ::

    public static double abs(int a) {
       if(a>0) {
         return a;
       }
       return (-a);
    }

 .. class:: comment

    La méthode proposée prend comme argument un entier alors que l'étudiant fournit un réel.	 

-
 ::

    public static double abs(double c) {
       double r;
       if(c<0) {
         r=-c;
       }
       return r;
    }

 .. class:: comment

    Cette méthode ne compile pas. La variable ``r`` peut être utilisée sans avoir été initialisée. C'est le cas par exemple lorsque ``c>0``. Le compilateur Java refusera de compiler cette méthode.

-
 ::

    public static double abs(double c) {
       if(c>=0) {
         return;
       }
       return (-c);
    }

 .. class:: comment

    Cette méthode ne compile pas. La première invocation de ``return`` ne retourne par de valeur tandis que la seconde retourne un réel.


Question 10. Les nombres amicaux
--------------------------------


Deux nombres entiers positifs sont dits `amicaux <http://fr.wikipedia.org/wiki/Nombre_amical>`_ si la somme des diviseurs entiers de l'un est égal à la somme des diviseurs entiers de l'autre. Pour vérifier si deux nombres sont amicaux, le plus simple est d'utiliser une méthode qui calcule la somme des diviseurs entiers d'un nombre et d'ensuite comparer les deux sommes. Supposons que cette méthode existe et est définie comme suit :

 ::

    /*
     * @pre : n>0
     * @post : retourne la somme des diviseurs entiers de n
     */
    public static int sdiv(int n) {
      // code non fourni
    }

Laquelle des méthodes ci-dessous retourne-t-elle ``true`` lorsque les deux nombres passés en argument sont amicaux et ``false``  sinon ?

.. class:: positive

-
 ::

    public static boolean amical(int a, int b) {
       int sdiv1=sdiv(a);
       int sdiv2=sdiv(b);
       return (sdiv1==sdiv2);
    }

-
 ::

    public static boolean amical(int a, int b) {
       return (sdiv(a)==sdiv(b));
    }

.. class:: negative

- 
 ::

    public static int amical(int a, int b) {
       int sdiv1=sdiv(a);
       int sdiv2=sdiv(b);
       return (sdiv1==sdiv2);
    }

 .. class:: comment
 
    Cette méthode est définie comme retournant un entier alors qu'elle retourne en fait un booléen. Elle ne se compile pas.


- 
 ::

    public static boolean amical(int a, int b) {
       int sdiv1=sdiv(a);
       int sdiv2=sdiv(b);
    }

 .. class:: comment
 
    Cette méthode est définie comme retournant un booléen alors qu'elle retourne rien. Elle ne se compile pas.


- 
 ::

    public static boolean amical(int c, int d) {
       sdiv1=sdiv(d);
       sdiv2=sdiv(c);
       return (sdiv1==sdiv2);
    }

 .. class:: comment
 
    Cette méthode ne se compile pas. Les variables ``sdiv1`` et ``sdiv2`` doivent être déclarées avant de pouvoir être utilisées.






.. include:: ../javanotes_toc.rst
