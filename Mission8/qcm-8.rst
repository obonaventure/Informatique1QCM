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


=====================
Mission 8. Interfaces
=====================


Ces questions supposent que vous avez lu les sections suivantes du livre de référence |jn|_ 

    - |jn4.5|_
        - |jn4.5.1|_
        - |jn4.5.2|_
        - |jn4.5.3|_
        - |jn4.5.4|_
    - |jn5.3|_
        - |jn5.3.1|_        
        - |jn5.3.2|_        
        - |jn5.3.3|_        
        - |jn5.3.4|_        
    - |jn5.5|_
        - |jn5.5.5|_        
    - |jn5.7|_    
        - |jn5.7.1|_
        - |jn5.7.2|_
 
Question 1. Packages
--------------------

Le package ``java.util`` définit (entre autres) l'interface ``List`` et une classe ``ArrayList`` qui implémente ``List``.  Sachant cela, parmi les fragments de programmes suivants, lequel est correct pour le compilateur Java ?

.. class:: positive

- ::

    import java.util.List;
    public Class MyList implements List {
        private List l;
        public MyList() {
            l = new java.util.ArrayList();
        }
        // ... autres méthodes de l'interface List
    }

- ::

    import java.util.*;
    public Class MyList implements List {
        private List l;
        public MyList() {
            l = new ArrayList();
        }
        // ... autres méthodes de l'interface List
    }

- ::

    public Class MyList implements java.util.List {
        private java.util.List l;
        public MyList() {
            l = new java.util.ArrayList();
        }
        // ... autres méthodes de l'interface List
    }
    
.. class:: negative

- ::

    import java.util.List;
    public Class MyList implements List {
        private List l;
        public MyList() {
            l = new ArrayList();
        }
        // ... autres méthodes de l'interface List
    }

  .. class:: comment
    
    Il faut soit importer ``ArrayList``, soit mettre ``java.util.ArrayList`` dans le constructeur.

- ::

    import java.util.ArrayList;
    public Class MyList implements List {
        private List l;
        public MyList() {
            l = new java.util.ArrayList();
        }
        // ... autres méthodes de l'interface List
    }

  .. class:: comment
    
    Il faut importer ``List`` et non ``ArrayList``.

- ::

    import java.*;
    public Class MyList implements List {
        private List l;
        public MyList() {
            l = new ArrayList();
        }
        // ... autres méthodes de l'interface List
    }
        
  .. class:: comment

    ``import java.*`` importe les classes (inexistantes) du package ``java`` , pas celles de ``java.util``.
    
- ::

    public Class MyList implements List {
        private java.util.List l;
        public MyList() {
            l = new java.util.ArrayList();
        }
        // ... autres méthodes de l'interface List
    }

  .. class:: comment
  
    Il faut soit importer ``List``, soit mettre ``java.util.List`` dans la déclaration de classe.
      
- ::

    public Class MyList implements List {
        private List l;
        public MyList() {
            l = new ArrayList();
        }
        // ... autres méthodes de l'interface List
    }

  .. class:: comment
  
    Il faut importer ``List`` et ``ArrayList``.
    
- ::

    public Class MyList implements java.util.List {
        private List l;
        public MyList() {
            l = new java.util.ArrayList();
        }
        // ... autres méthodes de l'interface List
    }

  .. class:: comment
  
    Il faut soit importer ``List``, soit mettre ``java.util.List`` dans la déclaration de la variable ``l``.
    
Question 2. Extension et implémentation
---------------------------------------

Parmi les ensembles d'affirmations suivantes, lequel est correct ?

.. class:: positive

-

    - Une classe ne peut étendre qu'une seule classe.
    - Une classe peut implémenter plusieurs interfaces.

.. class:: negative
    
-

    - Une classe peut étendre plusieurs classes.
    - Une classe peut implémenter plusieurs interfaces.

    .. class:: comment
    
    Une classe ne peut pas étendre plusieurs classes.
    
-

    - Une classe ne peut étendre qu'une seule classe.
    - Une classe ne peut implémenter qu'une seule interface.

    .. class:: comment
    
    Une classe peut implémenter plusieurs interfaces.

-

    - Une classe peut implémenter plusieurs interfaces.
    - Une interface peut implémenter une autre interface.

    .. class:: comment
    
    Une interface ne peut rien implémenter.

-

    - Une classe peut implémenter plusieurs interfaces.
    - Une interface peut étendre une classe.

    .. class:: comment
    
    Une interface ne peut pas étendre une classe.

            
Question 3. Interface
---------------------

Parmi les définitions de l'interface ``Direction`` ci-dessous, laquelle est correcte pour le compilateur Java?

.. class:: positive

- ::

    public interface Direction {        
        /** ... */
        public int value();
         
        /** ... */
        public void pivote(int angle);
    }

.. class:: negative

- ::

    public interface Direction {        
        /** ... */
        value();
         
        /** ... */
        pivote(int angle);
    }

  .. class:: comment
  
    Une interface contient des signatures de méthodes, pas uniquement des noms.

- ::

    public interface Direction {        
        private int value;  // la direction courante
        
        /** ... */
        public int value();
         
        /** ... */
        public void pivote(int angle);
    }

  .. class:: comment
  
    Une interface ne contient pas de variables d'instance.

- ::

    public interface Direction {        
        /** ... */
        public Direction(int val);

        /** ... */
        public int value();
         
        /** ... */
        public void pivote(int angle);
    }

  .. class:: comment
  
    Une interface ne contient pas de constructeur.

- ::

    public interface Direction {        
        /** ... */
        public int value() {
            return 0;
        }
         
        /** ... */
        public void pivote(int angle) {
            // rien
        }
    }

  .. class:: comment
  
    Une interface ne contient que des signatures, pas de corps de méthodes.

- ::

    public interface Direction {        
        private int value;  // la direction courante

        /** ... */
        public Direction(int val);

        /** ... */
        public int value();
         
        /** ... */
        public void pivote(int angle);
    }

  .. class:: comment
  
    Une interface ne contient in variable d'instance, ni constructeur.
    

   
Question 4. Interface et implémentation
---------------------------------------

On considère l'interface ``Prix`` définie comme suit ::

    public interface Prix {
        /**
         * @pre  -
         * @post retourne le montant du prix
         */
        public int getVal();
        /**
         * @pre  -
         * @post change le montant du prix
         */
        public void setVal(int x);
    }
    
Parmi les classes suivantes, laquelle est une implémentation correcte de ``Prix`` ?

.. class:: positive

- ::

    public class MyPrix implements Prix {
        private it val;  // montant du prix
        public MyPrix(int v) {
            val = v;     
        }
        public int getVal() {
            return val;
        }
        public int getVal(double tax) {
            return (int) (val * (1 + tax));
        }
        public void setVal(int x) {
            val = x;
        }
        public void setVal(double x) {
            val = (int) x;
        }
    }

- ::

    public class MyPrix implements Prix {
        private it val;  // montant du prix
        public MyPrix(int v) {
            val = v;     
        }
        public int getVal() {
            return val;
        }
        public void setVal(int x) {
            val = x;
        }
    }
    
.. class:: negative

- ::

    public class MyPrix {
        private it val;  // montant du prix
        public MyPrix(int v) {
            val = v;     
        }
        public int getVal() {
            return val;
        }
        public void setVal(int x) {
            val = x;
        }
    }
    
  .. class:: comment
  
    Il manque la clausse ``implements`` dans l'en-tête de classe.
    

- ::

    public class MyPrix implements Prix {
        private it val;  // montant du prix
        public MyPrix(int v) {
            val = v;     
        }
        public int getVal() {
            return val;
        }
        public int getVal(double tax) {
            return (int) (val * (1 + tax));
        }
        public void setVal(double x) {
            val = (int) x;
        }
    }
    
  .. class:: comment
  
    La méthode ``void setVal(int x)`` n'est pas implémentée, attention à la signature!
    
- ::


    public class MyPrix implements Prix {
        private it val;  // montant du prix
        public MyPrix(int v) {
            val = v;     
        }
        public int getVal(double tax) {
            return (int) (val * (1 + tax));
        }
        public void setVal(int x) {
            val = x;
        }
    }
    
  .. class:: comment
  
    La méthode ``int getVal()`` n'est pas implémentée, attention à la signature!

- ::


    public class Prix implements MyPrix {
        private it val;  // montant du prix
        public MyPrix(int v) {
            val = v;     
        }
        public int getVal() {
            return val;
        }
        public void setVal(int x) {
            val = x;
        }
    }
    
  .. class:: comment
  
    C'est ``MyPrix`` qui implémente ``Prix`` et non l'inverse.
    
- ::

    public class MyPrix implements Prix {
        private it val;  // montant du prix
        public MyPrix(int v) {
            val = v;     
        }
        public int getVal() {
            return val;
        }
        public int getVal(double tax) {
            return (int) (val * (1 + tax));
        }
        public int setVal(int x) {
            val = x;
            return x;
        }
    }
    
  .. class:: comment
  
    La signature de ``setVal`` ne correspond pas à celle de l'interface.

Question 5.  Interfaces et types
--------------------------------


Soit l'interface ``I1`` et les classes ``C2`` et ``C3`` définies comme suit ::

    public interface I1 {
        // ...
    }

    public class C2 implements I1 {
        public C2() {
            // ...
        }
        // ...
    }

    public class C3 extends C2 {
        public C3() {
            // ...
        }
        // ...
    }

Parmi les portions de code suivantes, laquelle est valide pour le compilateur Java ?

.. class:: positive

- ::

    C2 obj2 = new C2();
    C3 obj3 = new C3();
    I1 ojb1 = obj2;
    
    
- ::

    C3 obj3 = new C3();    
    I1 obj1 = new C3();
    C2 obj2 = new C2();
    
.. class:: negative

- ::

    I1 ojb1 = new C2();
    C2 obj2 = obj1;
    C3 obj3 = new C3();
 
  .. class:: comment
  
    ``C2 obj2`` ne peut pas recevoir une expression de type ``I1``.

- ::

    C3 obj3 = new C2();
    I1 obj1 = new C2();
    C2 obj2 = obj3;

  .. class:: comment
  
    ``I1 obj1`` ne peut pas recevoir une expression de type ``C2``.

- ::

    C2 obj2 = new C2();
    I1 ojb1 = obj2;
    C3 obj3 = obj2;

  .. class:: comment
  
    ``C3 obj3`` ne peut pas recevoir une expression de type ``I2``.

- ::

    C3 obj3 = new C3();
    I1 obj1 = new C2();
    C2 obj2 = obj1;

  .. class:: comment
  
    ``C2 obj2`` ne peut pas recevoir une expression de type ``I1``.

.. =================================================
.. include:: ../javanotes_toc.rst
