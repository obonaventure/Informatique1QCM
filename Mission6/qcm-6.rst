.. Copyright |copy| 2013 Charles Pecheur

.. raw:: html

  <link href="css/prettify.css" type="text/css" rel="stylesheet" />
  <script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
  <script type="text/javascript" src="js/jquery-shuffle.js"></script>
  <script type="text/javascript" src="js/prettify.js"></script>
  <script type="text/javascript" src="js/rst-form.js"></script>
  <script type="text/javascript">$nmbr_prop = 4</script> 

.. _TextIO : http://math.hws.edu/eck/cs124/javanotes6/source/TextIO.java
.. |TextIO| replace:: ``TextIO``


============================
Mission 6. Classes et Objets
============================


Ces questions supposent que vous avez lu les sections suivantes du livre de référence |jn|_ 

  - |jn5.1|_

    - |jn5.1.1|_
    - |jn5.1.2|_
    - |jn5.1.3|_

  - |jn5.2|_

    - |jn5.2.1|_
    - |jn5.2.2|_
    - |jn5.2.3|_

  - |jn5.4|_
  

    - |jn5.4.1|_
    - |jn5.4.2|_
    - |jn5.4.3|_
    
ainsi que l'API de la classe |TextIO|_.  Les sections vues précédemment restent bien entendu d'actualité.

Question 1. Classe, objets et instances
---------------------------------------

Soit le code Java suivant ::

    public class PairOfDice {
    
        public int die1;   // Number showing on the first die.
        public int die2;   // Number showing on the second die.
        
        /**
         * @pre val1, val2 are valid die values
         * @post creates a pair of dice that are initially 
         *       showing the values val1 and val2.
         */
        public PairOfDice(int val1, int val2) {
             die1 = val1; 
             die2 = val2;  
        }
    
        /**
         * @pre -
         * @post rolled the dice by setting each of the dice 
         *       to be a random number between 1 and 6.
         */
        public void roll() {
             die1 = (int)(Math.random()*6) + 1;
             die2 = (int)(Math.random()*6) + 1;
        }
        
    } // end class PairOfDice    

Laquelle des propositions ci-dessous est correcte ? 

.. class:: positive

- 
  * Ce code définit une classe ``PairOfDice``.  
  * Chaque instance de ``PairOfDice`` a sa propre copie de ``die1``.
  * ``roll()`` est une méthode d'instance de la classe ``PairOfDice``.

-
  * Une instance de ``PairOfDice`` est un objet.
  * ``die1`` est une variable d'instance de la classe ``PairOfDice``.  
  * L'effet de l'exécution de la méthode ``roll()`` dépend de l'instance à laquelle elle s'applique.

.. class:: negative

- 
  * Ce code définit un objet ``PairOfDice``.  
  * ``die1`` est une variable d'instance de la classe ``PairOfDice``.  
  * ``roll()`` est une méthode d'instance de la classe ``PairOfDice``.

  .. class:: comment

    Ce code définit une *classe*, pas un objet.

-
  * Une instance de ``PairOfDice`` est un objet.
  * ``die1`` est une variable partagée entre les instances de ``PairOfDice``.
  * ``roll()`` est une méthode d'instance de la classe ``PairOfDice``.

  .. class:: comment

    ``die1`` est une variable d'instance, elle n'est pas partagée.

-
  * Une instance de ``PairOfDice`` est un objet.
  * Chaque instance de ``PairOfDice`` a sa propre copie de ``die1``.
  * ``roll()`` est une méthode de classe de la classe ``PairOfDice``.

  .. class:: comment

    ``roll()`` est une méthode d'instance.
    
-
  * Une instance de ``die1`` est un entier.
  * Chaque instance de ``PairOfDice`` a sa propre copie de ``die1``.
  * L'effet de l'exécution de la méthode ``roll()`` dépend de l'instance à laquelle elle s'applique.

  .. class:: comment

    La notion d'instance s'applique aux classes et aux objets, pas aux variables.

-
  * Ce code définit une classe ``PairOfDice``.  
  * ``die1`` est une variable locale de la classe ``PairOfDice``.  
  * L'effet de l'exécution de la méthode ``roll()`` dépend de l'instance à laquelle elle s'applique.

  .. class:: comment

    Une variable locale est définie à l'intérieur du corps d'une méthode.

-
  * Une instance de ``PairOfDice`` est un objet.
  * ``die1`` est une variable d'instance de la classe ``PairOfDice``.  
  * L'effet de l'exécution de la méthode ``roll()`` est indépendant de l'instance à laquelle elle s'applique.

  .. class:: comment

    ``roll()`` est une méthode d'instance et utilise les variables d'instance de la classe.

Question 2. Définition de classe
--------------------------------

Laquelle des définitions suivantes définit correctement une classe dont les instances représentent des fractions (num / den), telle que les instructions ::

  Fraction f = new Fraction(3,4);
  System.out.println(f.valeur());

imprime le résultat ``0.75``  ?

.. class:: positive

- ::

    public class Fraction {
        private int num;  // numérateur
        private int den;  // dénominateur
        
        public Fraction(int n, int d) {
            num = n;
            den = d;
        }
        
        public double valeur() {
            return ((double) num) / ((double) den);
        }
    }

.. class:: negative

- ::

    public class Fraction {
        private int num;  // numérateur
        private int den;  // dénominateur
        
        public Fraction(int n, int d) {
            num = n;
            den = d;
        }
        
        public static double valeur() {
            return ((double) num) / ((double) den);
        }
    }

  .. class:: comment

    La méthode ``valeur`` doit être une méthode d'instance, pour avoir accès aux variables d'instance de chaque instance de ``Fraction``.

- ::

    public class Fraction {
        private int num;  // numérateur
        private int den;  // dénominateur
        
        public void Fraction(int n, int d) {
            num = n;
            den = d;
        }
        
        public double valeur() {
            return ((double) num) / ((double) den);
        }
    }

  .. class:: comment

    La signature du constructeur est incorrecte.

- ::

    public class Fraction {
        private int num;  // numérateur
        private int den;  // dénominateur
        
        public Fraction(int n, int d) {
            new Fraction(n,d);
            num = n;
            den = d;
        }
        
        public double valeur() {
            return ((double) num) / ((double) den);
        }
    }

  .. class:: comment

    La construction 'new Fraction(n,d)' fait appel au constructeur, elle ne doit pas se trouver dans la définition de ce constructeur.

- ::

    public class Fraction {
        private int num = 0;  // numérateur
        private int den = 1;  // dénominateur
        
        public Fraction(int n, int d) {
            num = n;
            den = d;
        }
        
        public double valeur(Fraction f) {
            return ((double) num) / ((double) den);
        }
    }

  .. class:: comment

    Dans ``valeur``, il n'est pas nécessaire de passer la fraction comme paramètre.


Question 3. Initialisation d'objets
-----------------------------------

Sur base de la définition de la question précédente, que se passe-t-il si on tente de compiler et d'exécuter (séparément) les trois suites d'instructions suivantes ?

1. ::

    Fraction f;
    System.out.println(f.valeur());
    
2. ::

    Fraction f = new Fraction(3, 4);
    System.out.println(f.valeur());

3. ::

    Fraction f = null;
    System.out.println(f.valeur());
    
.. class:: positive

-
  1. Erreur à l'exécution: ``f`` est une référence nulle
  2. Imprime "0.75"
  3. Erreur à l'exécution: ``f`` est une référence nulle

.. class:: negative

-
  1. Imprime "0.0"
  2. Imprime "0.75"
  3. Erreur à l'exécution: ``f`` est une référence nulle

  .. class:: comment

    Dans le cas 1, ``f`` n'est pas initialisé donc ne référencie aucun objet.
    
-
  1. Erreur à l'exécution: ``f`` est une référence nulle
  2. Imprime "0.75"
  3. Imprime "0.0"

  .. class:: comment

    La référence ``null`` ne référencie aucun objet, le cas 3 est identique au cas 1.
    
-
  1. Erreur de compilation
  2. Imprime "0.75"
  3. Erreur de compilation

  .. class:: comment

    Les trois sont corrects par rapport à la syntaxe et aux types, la compilation ne pose pas de problème.
    
-
  1. Imprime "0.0"
  2. Imprime "0.75"
  3. Imprime "0.0"

  .. class:: comment

    Dans les cas 1 et 3, ``f`` ne référencie aucun objet.
    
    
Question 4. Accesseurs et mutateurs
-----------------------------------

Comment définirait-on un accesseur (getter) et un mutateur (setter) pour la variable d'instance ``num`` de la classe ``Fraction`` à la question 2, tels qu'utilisés dans l'exemple suivant ::

  Fraction f = new Fraction(3, 4);
  System.out.println(f.getNum());  // imprime "3"
  f.setNum(5);
  System.out.println(f.getNum());  // imprime "5"

.. class:: positive

- ::

    public int getNum() {
        return num;
    }
    public void setNum(int n) {
        num = n;
    }
    
.. class:: negative

- ::

    public int getNum() {
        System.out.println(num);
    }
    public void setNum() {
        num = TextIO.getInt();
    }

  .. class:: comment

    Il s'agit de permettre au reste du programme de lire et modifier la variable, pas à l'utilisateur.

- ::

    public void getNum(int n) {
        n = num;
    }
    public void setNum(int n) {
        num = n;
    }
    
  .. class:: comment

    La méthode ``getNum()`` ne sert à rien tel que définie ici.

- ::

    public int getNum() {
        return num;
    }
    public int setNum(int n) {
        num = n;
        return num;
    }

  .. class:: comment

    Dans ``setNum()``, pourquoi retourner la valeur modifiée?

- ::

    public int f1() {
        return num;
    }
    public void f2(int n) {
        num = n;
    }

  .. class:: comment

    Ceci peut fonctionner, mais pourquoi prendre des noms de méthode qui ne signifient rien et violent les conventions usuelles ?  La lisibilité du code est un facteur de qualité important.


Question 5. Constructeurs
-------------------------

Soit la classe suivante ::

    public class Etudiant {
        String nom;
        String matricule;
        boolean bisseur = false;
             
        // ... méthodes
    }

Parmi les définitions de constructeurs suivantes, laquelle est correcte ?

.. class:: positive

- ::

    // un étudiant non-bisseur 
    public Etudiant(String n, String m) {
        nom = n;
        matricule = m;
    }
     
- ::
   
    // un étudiant anonyme
    public Etudiant(String m, boolean b) {
        nom = "[anonyme]";
        matricule = m;
        bisseur = b;
    }
    
.. class:: negative

- ::
   
    // un étudiant bisseur 
    public Bisseur(String n, String m) {
        nom = n;
        matricule = m;
        bisseur = true;
    }
     
  .. class:: comment

    Le constructeur doit avoir le nom de la classe.

- ::
   
    // un étudiant sans matricule
    public static Etudiant(String n, boolean b) {
        nom = n;
        matricule = "000000";
        bisseur = b;
    }

  .. class:: comment

    Un constructeur ne peut pas être déclaré ``static``.

- ::
   
    // un étudiant anonyme 
    public Etudiant(String m) {
        matricule = m;
        bisseur = false;
    }
     
  .. class:: comment

    La variable ``nom`` n'est pas initialisée.

- ::
   
    // un étudiant non-bisseur 
    public Etudiant(String n, String m) {
        nom = n;
        matricule = m;
        return;
    }

  .. class:: comment

    L'instruction ``return`` est superflue et interdite dans un constructeur.


Question 6. Références
----------------------

Soit la classe ``Compteur`` suivante ::

    public class Compteur {
        private int compte;  // le compteur
        
        public Compteur(int n) {
            compte = n;
        }
        
        public void ajout(int n) {
            compte = compte + n;
        }
        
        public int valeur() {
            return compte;
        }
    }
    
Qu'imprime le programme suivant ::

        Compteur c1 = new Compteur(10);
        Compteur c2 = new Compteur(20);
        c1.ajout(5);
        System.out.println(c1.valeur() + "," + c2.valeur());
        c1.ajout(10);
        c1 = c2;
        c2.ajout(20);
        System.out.println(c1.valeur() + "," + c2.valeur());
        c2 = new Compteur(0);
        System.out.println(c1.valeur() + "," + c2.valeur());

.. class:: positive

- ::

    15,20
    40,40
    40,0

.. class:: negative

- ::

    15,20
    20,40
    20,0

  .. class:: comment

    Après l'instruction ``c1 = c2``, ``c1`` et ``c2`` sont des références au même objet; ``c2.ajout(20)`` agit aussi sur l'objet référencé par ``c1``.

- ::

    15,20
    40,40
    0,0

  .. class:: comment

    Après ``c2 = new Compteur(0)``, seule ``c2`` réfère au nouvel objet créé; ``c1`` est inchangé.

- ::

    15,20
    25,40
    25,0

  .. class:: comment

    Attention à l'instruction ``c1 == c2``.

- ::

    10,20
    20,20
    20,0

  .. class:: comment

    Que fait la méthode ``ajout()`` ?
      

Question 7. toString()
----------------------

Comment écrirait-on une méthode pour la classe ``Etudiant`` de la question 5, telle que le code suivant ::

    Etudiant etud = new Etudiant("John Doe", "987612");
    System.out.println(etud);
    
affiche le texte suivant :

    ``John Doe (987612) non-bisseur``
    
.. class:: positive

- ::

        public String toString() {
            String s = nom + " (" + matricule + ")";
            if (bisseur) {
                s = s + " bisseur";
            } else {
                s = s + " non-bisseur";
            }
            return s;
        }

.. class:: negative

- ::

        public String asString() {
            String s = nom + " (" + matricule + ")";
            if (bisseur) {
                s = s + " bisseur";
            } else {
                s = s + " non-bisseur";
            }
            return s;
        }

  .. class:: comment

    La méthode doit s'appeler ``toString`` pour pouvoir être appelée implicitement, par exemple dans ``System.out.println``.

- ::

        public String toString(String s) {
            s = nom + " (" + matricule + ")";
            if (bisseur) {
                s = s + " bisseur";
            } else {
                s = s + " non-bisseur";
            }
            return s;
        }

  .. class:: comment

    La méthode doit avoir exactement la signature ``String toString()`` pour pouvoir être appelée implicitement, par exemple dans ``System.out.println``.

- ::

        public String toString() {
            return nom + " (" + matricule + ")";
            if (bisseur) {
                return " bisseur";
            } else {
                return " non-bisseur";
            }
        }

  .. class:: comment

    Seul le premier ``return`` exécuté sera pris en compte.  Révisez les appels de méthodes.

- ::

        public String toString() {
            System.out.println(nom + " (" + matricule + ")";
            if (bisseur) {
                System.out.println(" bisseur");
            } else {
                System.out.println(" non-bisseur");
            }
        }

  .. class:: comment

    La méthode ``toString()`` doit retourner le string et non l'imprimer.

- ::

        public String toString() {
            String s = nom + " (" + matricule + ")";
            if (bisseur) {
                s = s + " bisseur";
            } else {
                s = s + " non-bisseur";
            }
        }

  .. class:: comment

    Cette méthode ne retourne rien...

Question 8.  TextIO
-------------------

Parmi les portions de programme suivantes, laquelle permet d'imprimer à la console le contenu du fichier ``README`` ?

.. class:: positive

- ::

    TextIO.readFile("README");
    while (!TextIO.eof()) {
        System.out.println(TextIO.getln());
    }

.. class:: negative

- ::

    TextIO.readFile("README");
    while (true) {
        System.out.println(TextIO.getln());
    }

  .. class:: comment
  
    Cette version produira une erreur à la fin du fichier.

- ::

    while (!TextIO.eof("README")) {
        System.out.println(TextIO.getln("README"));
    }

  .. class:: comment
  
    L'utilisation de ``eof()`` et ``getln()`` ne correspond pas à leur signature documentée dans l'API.  Ce code donne donne une erreur de compilation.

- ::

    TextIO.open("README");
    while (TextIO.hasNext()) {
        System.out.println(TextIO.next());
    }

  .. class:: comment
  
    Ces noms de méthodes n'existent pas dans ``TextIO``.

- ::

    TextIO.readFile("README");
    while (TextIO.eof()) {
        System.out.println(TextIO.getWord());
    }

  .. class:: comment
  
    Deux erreurs: un caractère manquant (qui change tout) dans la condition du ``while`` et l'utilisation inappropriée de ``getWord()``.

- ::

    TextIO.readFile("README");
    String s = TextIO.getln();
    while (!TextIO.eof(s)) {
        System.out.print(s);
        s = TextIO.getln();
    }

  .. class:: comment
  
    Ce n'est pas ainsi qu'on utilise ``TextIO.eof()``.

.. -------------------------------------------
.. include:: ../javanotes_toc.rst
