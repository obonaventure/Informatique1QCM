.. Copyright |copy| 2013 Charles Pecheur

.. raw:: html

  <link href="css/prettify.css" type="text/css" rel="stylesheet" />
  <script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
  <script type="text/javascript" src="js/jquery-shuffle.js"></script>
  <script type="text/javascript" src="js/prettify.js"></script>
  <script type="text/javascript" src="js/rst-form.js"></script>
  <script type="text/javascript">$nmbr_prop = 4</script> 

.. _Arrays : http://docs.oracle.com/javase/1.5.0/docs/api/java/util/Arrays.html
.. |Arrays| replace:: ``java.util.Arrays``
.. _Scanner : http://docs.oracle.com/javase/1.5.0/docs/api/java/util/Scanner.html
.. |Scanner| replace:: ``java.util.Scanner``


=====================
Mission 10. ArrayList
=====================


Ces questions supposent que vous avez lu les sections suivantes du livre de référence |jn|_ 

    - |jn8.3|_
        - |jn8.3.3|_        
        - |jn8.3.4|_        
        - |jn8.3.5|_        
    - |jn10.1|_    
        - |jn10.1.3|_
        - |jn10.1.4|_
        - |jn10.1.5|_
        - |jn10.1.6|_
        - |jn10.1.7|_
    - |jn10.2|_    
        - |jn10.2.1|_
        - |jn10.2.2|_
    - |jn11.4|_    
        - |jn11.4.1|_
        
Question 1. Instruction ``throw``
----------------------------------

Quelle est la manière correcte de lancer une exception de type ``IllegalArgumentException`` signalant un nombre négatif ?


.. class:: positive

- ::

    throw new IllegalArgumentException("nombre negatif");

- ::

    Exception e = new IllegalArgumentException("nombre negatif");
    throw e;

  .. class:: comment
  
    L'exception ne doit pas nécessairement être créée dans l'instruction ``throw``.



.. class:: negative

- ::

    throw IllegalArgumentException("nombre negatif");

  .. class:: comment
    
    ``IllegalArgumentException`` est un constructeur.

- ::

    return new IllegalArgumentException("nombre negatif");

  .. class:: comment
    
    Il ne s'agit pas de retourner un résultat mais de lancer une exception.

- ::

    try {
        ...
    } catch (IllegalArgumentException e) {
        e.setMessage("nombre negatif");
    }

  .. class:: comment
    
    Il s'agit de lancer une exception, pas de l'intercepter.

- ::

    try {
        ...
    } catch (new IllegalArgumentException("nombre negatif")) {
        System.out.println(e.getMessage());
    }

  .. class:: comment
    
    Il s'agit de lancer une exception, pas de l'intercepter.

- ::

    throws new IllegalArgumentException("nombre negatif");

  .. class:: comment
    
    ``throws`` intervient dans les signatures, ce n'est pas la bonne instruction.
        
Question 2. Propagation d'exceptions
---------------------------------------

Qu'imprime le programme suivant ::

    public static void main(String[] args) {
        System.out.println("Debut de main");
        task1();
        task2();
        System.out.println("Fin de main");
    }
    
    public static void task1() {
        System.out.println("Debut de task1");
        try {
            task3();
        } catch (Exception e) {
            System.out.println("task1 intercepte " + e.getMessage());
        }
        System.out.println("Fin de task1");
    }
    
    public static void task2() {
        System.out.println("Debut de task2");
        task3();
        System.out.println("Fin de task2");
    }

    public static void task3() {
        System.out.println("Debut de task3");
        task4();
        System.out.println("Fin de task3");
    }
    
    public static void task4() {
        System.out.println("Debut de task4");
        throw new RuntimeException("boum");
        System.out.println("Fin de task4");
    }
    
.. class:: positive

- ::

    Debut de main
    Debut de task1
    Debut de task3
    Debut de task4
    task1 intercepte boum
    Fin de task1
    Debut de task2
    Debut de task3
    Debut de task4
    java.lang.Exception: boum    

.. class:: negative

- ::

    Debut de main
    Debut de task1
    Debut de task3
    Debut de task4
    Fin de task4
    Fin de task3
    task1 intercepte boum
    Fin de task1
    Debut de task2
    Debut de task3
    Debut de task4
    Fin de task4
    Fin de task3
    Fin de task2
    Fin de main
    java.lang.Exception: boum    

  .. class:: comment
    
    L'exécution de ``main``, ``task2``, ``task3`` et ``task4`` ne parvient pas à la fin à cause de l'exception lancée dans ``task4``.

- ::

    Debut de main
    Debut de task1
    Debut de task3
    Debut de task4
    Fin de task3
    task1 intercepte boum
    Fin de task1
    Debut de task2
    Debut de task3
    Debut de task4
    Fin de task3
    java.lang.Exception: boum    

  .. class:: comment
    
    L'exécution de ``task3`` ne parvient pas à la fin, ``task3`` propage l'exception de ``task4``.

- ::

    Debut de main
    Debut de task1
    Debut de task3
    Debut de task4
    task1 intercepte boum
    Debut de task2
    Debut de task3
    Debut de task4
    java.lang.Exception: boum    

  .. class:: comment
    
    L'exécution de ``task1`` parvient à la fin, l'exception de ``task3`` est interceptée et traitée.

- ::

    Debut de main
    Debut de task1
    Debut de task3
    Debut de task4
    java.lang.Exception: boum    
    task1 intercepte boum
    Fin de task1
    Debut de task2
    Debut de task3
    Debut de task4
    java.lang.Exception: boum    

  .. class:: comment
    
    La première exception lancée dans ``task4`` est interceptée dans ``task1``, elle ne s'affiche pas.

- ::

    Debut de main
    Debut de task1
    Debut de task3
    Debut de task4
    task1 intercepte boum
    Fin de task4
    Fin de task3
    Fin de task1
    Debut de task2
    Debut de task3
    Debut de task4
    java.lang.Exception: boum    
    Fin de task4
    Fin de task3
    Fin de task2
    Fin de main

  .. class:: comment
    
    L'exécution de ``main``, ``task2``, ``task3`` et ``task4`` ne parvient pas à la fin à cause de l'exception lancée dans ``task4``.
        
Question 3. Déclaration ``throws``
------------------------------------

Quelle est la manière correcte de déclarer que la méthode ``readName`` peut causer une ``IOException`` ?

.. class:: positive

- ::

    import java.io.*;
    ...
    public String readName(Reader r) throws IOException {
        ...
    }

.. class:: negative

- ::

    import java.io.*;
    ...
    public String readName(Reader r) throws new IOException() {
        ...
    }

  .. class:: comment
    
    ``throws`` est suivi d'un nom de classe, pas d'une expression.

- ::

    import java.io.*;
    ...
    public String readName(Reader r) {
        throws new IOException(); 
        ...
    }

  .. class:: comment
    
    Il faut déclarer l'exception dans la signature et non la lancer dans le corps de la méthode.

- ::

    import java.io.*;
    ...
    public String readName(Reader r) throw IOException {
        ...
    }

  .. class:: comment
    
    ``throw`` est une instruction, ce n'est pas ce qu'il faut ici.

- ::

    import java.io.*;
    ...
    // throws IOException 
    public String readName(Reader r) {
        ...
    }

  .. class:: comment
    
    ``throws`` doit intervenir dans la signature, pas juste en commentaire.

- ::

    import java.io.*;
    ...
    public IOException readName(Reader r) {
        ...
    }

  .. class:: comment
    
    ``readName`` peut lancer une ``IOException`` et non la retourner comme résultat.
        
Question 4. Exceptions sous contrôle
-------------------------------------

Considérons le programme suivant ::

    import java.io.*;
    ...
    
    public static void main(String[] args) {
        processFile(args[0]);
    }
    
    public static void processFile(String filename) {
        try {
            String[] lines = readFile(filename);
            ...
        } catch (IOException e) {
            System.out.println("cannot read: " + e.getMessage());
        }
    }

    public static String[] readFile(String filename) {
        BufferedReader r = new BufferedReader(new FileReader(filename));
        ...
        for (String s = r.readLine(); s != null; s = r.readLine()) {
            ...
        }
        r.close();
        return ...;
    }
    
Comment doit-on compléter les signatures des trois méthodes pour avoir toutes les déclarations ``throws`` nécessaires, sans déclarations inutiles ?

.. class:: positive

- ::

    public static void main(String[] args)
    public static void processFile(String filename)
    public static String[] readFile(String filename) throws IOException

.. class:: negative

- ::

    public static void main(String[] args)
    public static void processFile(String filename) throws IOException
    public static String[] readFile(String filename) throws IOException

  .. class:: comment
    
    ``processFile`` intercepte ``IOException``, il ne la propage pas.

- ::

    public static void main(String[] args) throws IOException
    public static void processFile(String filename) throws IOException
    public static String[] readFile(String filename) throws IOException

  .. class:: comment
    
    ``processFile`` intercepte ``IOException``, il ne la propage pas et ``main`` non plus.

- ::

    public static void main(String[] args)
    public static void processFile(String filename) throws IOException
    public static String[] readFile(String filename) 

  .. class:: comment
    
    C'est ``readFile`` et non ``processFile`` qui peut causer une ``IOException``, à cause de l'utilisation du ``BufferedReader``.

- ::

    public static void main(String[] args) throws IOException
    public static void processFile(String filename)
    public static String[] readFile(String filename) throws IOException

  .. class:: comment
    
    Puisque ``processFile`` intercepte ``IOException``, il ne la propage pas à ``main``.
        
Question 5. Définition d'exceptions
-------------------------------------

Parmi les définitions suivantes, laquelle définit correctement une exception hors contrôle (unchecked) ?

.. class:: positive

- ::

    public class GraveException extends RuntimeException {
        public GraveException(String msg) {
            super(msg);
        }
    }

.. class:: negative


- ::

    public class GraveException extends RuntimeException {
        private String message;
        public GraveException(String msg) {
            this.message = msg;
        }
    }

  .. class:: comment
    
    C'est syntaxiquement correct mais inadéquat; ``RuntimeException`` contient déjà un message.
    
- ::

    public class GraveException extends Exception {
        public GraveException(String msg) {
            super(msg);
        }
    }

  .. class:: comment
    
    Cette exception n'est pas hors contrôle.
    
- ::

    public class GraveException {
        public GraveException(String msg) {
            super(msg);
        }
    }

  .. class:: comment
    
    Pour que ce soit une exception il faut définir une sous-classe de ``Throwable``.
    
- ::

    public class GraveException extends RuntimeException {
        public GraveException(String msg) {
            throw new GraveException(msg);
        }
    }

  .. class:: comment
    
    L'utilisation de ``throw`` n'a pas de sens ici.
        
Question 6. Les collections Java
-----------------------------------

Quel groupe d'affirmations est correct ?

.. class:: positive

- ``List<T>`` est une interface qui représente une séquence ordonnée d'éléments de type ``T``.  ``ArrayList<T>`` et ``LinkedList<T>`` sont des implémentations de ``List<T>``, basées respectivement sur des tableaux et sur des structures chaînées.

.. class:: negative

- ``List<T>`` est une classe qui représente une séquence ordonnée d'éléments de type ``T``.  ``ArrayList<T>`` et ``LinkedList<T>`` sont des extensions de ``List<T>``, basées respectivement sur des tableaux et sur des structures chaînées.

  .. class:: comment
    
    ``List<T>`` est une interface.

- ``List<T>`` est une interface qui représente un ensemble d'éléments de type ``T``.  ``HashList<T>`` et ``LinkedList<T>`` sont des implémentations de ``List<T>``, basées respectivement sur des tables de hachage et sur des liens hypertexte.

  .. class:: comment
    
    ``List<T>`` ne représente pas un ensemble mais une séquence ordonnée.

- ``List<T>`` est une classe qui représente une séquence ordonnée d'``Object`` de taille ``T``.  ``ArrayList<T>`` et ``LinkedList<T>`` sont des extensions de ``List<T>``, basées respectivement sur des tableaux et sur des structures chaînées.

  .. class:: comment
    
    ``T`` est le type des éléments et non la taille de la séquence.

- ``List<T>`` est une interface qui représente un ensemble d'éléments de type ``T``.  ``HashList<T>`` et ``LinkedList<T>`` sont des implémentations de ``List<T>``, basées respectivement sur des tables de hachage et sur des structures chaînées.

  .. class:: comment
    
    ``HashList<T>`` n'existe pas dans les collections Java.
        
Question 7. ``ArrayList<T>``
------------------------------

Parmi les fragments de progamme suivants, lequel utilise correctement la classe ``ArrayList<T>`` ?

.. class:: positive

- ::

    import java.util.*;
    ...
    List<String> list = new ArrayList<String>();
    list.add("Hello");
    String s1 = "World";
    list.add(s1);
    int i = list.indexOf("Hello");
    String s2 = list.get(i);
    
.. class:: negative

- ::

    import java.util.*;
    ...
    List<String> list = new ArrayList<String>[10];
    list.add("Hello");
    Object s1 = "World";
    list.add(s1);
    int i = list.indexOf("Hello");
    String s2 = (String) list.get(i);

  .. class:: comment

    ``list.add(s1)`` provoque une erreur de type et le type-cast à la dernière ligne est incorrect.

- ::

    import java.util.*;
    ...
    List<String> list = new ArrayList<String>[10];
    list[0] = "Hello";
    String s1 = "World";
    list[1] = s1;
    int i = list.indexOf("Hello");
    String s2 = list[i];

  .. class:: comment

    ``ArrayLsit`` n'est pas un tableau ; ``list[i]`` est syntaxiquement incorrect.

- ::

    import java.util.*;
    ...
    List<T> list = new ArrayList();
    list.add("Hello");
    String s1 = "World";
    list.add(s1);
    int i = list.indexOf("Hello");
    String s2 = list.get(i);

  .. class:: comment

    Le paramètre de type ``<T>`` doit être un type particulier existant, ici ``<String>``.
    
- ::

    import java.util.*;
    ...
    List<String> list = new ArrayList<String>[10];
    add(list, "Hello");
    String s1 = "World";
    add(list, s1);
    int i = list.indexOf("Hello");
    String s2 = list.get(i);

  .. class:: comment

    ``add`` est une méthode de ``list``.
        
Question 8. Itérateurs
--------------------------

Parmi les fragments suivants, lequel utilise correctement un itérateur ?

.. class:: positive

- ::

    List<Integer> list = makeList();  // crée la liste
    Iterator<Integer> iter = list.iterator();
    while (iter.hasNext()) {
        Integer i = iter.next();
        System.out.println(i);
    }

.. class:: negative

- ::

    List<Integer> list = makeList();  // crée la liste
    while (list.hasNext()) {
        Integer i = list.next();
        System.out.println(i);
    }

  .. class:: comment
    
    ``list`` n'est pas un itérateur.

- ::

    List<Integer> list = makeList();  // crée la liste
    Iterator iter = list.iterator();
    while (iter.hasNext()) {
        Integer i = iter.next();
        System.out.println(i);
    }

  .. class:: comment
    
    Erreur de typage, utiliser un type générique pour ``iter``.

- ::

    List<Integer> list = makeList();  // crée la liste
    Iterator<Integer> iter = list.iterator();
    while (hasNext(iter)) {
        Integer i = next(iter);
        System.out.println(i);
    }

  .. class:: comment
    
    ``hasNext`` et ``next`` sont des méthodes de ``iter``.

- ::

    List<Integer> list = makeList();  // crée la liste
    Iterator<Integer> iter = list.iterator();
    while (iter.hasNext()) {
        Integer i = (Integer) iter.next();
        System.out.println(i);
    }

  .. class:: comment
    
    Le type-cast est inutile, ``iter.next`` retourne un ``Integer``.

- ::

    List<Integer> list = makeList();  // crée la liste
    Iterator<Integer> iter = list.iterator();
    while (iter.next() != null) {
        Integer i = iter.next();
        System.out.println(i);
    }

  .. class:: comment
    
    Le test de boucle est incorrect.

.. =================================================
.. include:: ../javanotes_toc.rst
