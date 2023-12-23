/*Collection Module
This module is to represent a family of collections of elements of any type, such as, collection of int-type data, collection of double-type data, collection of Book-type data, etc.

You create a templated class called Collection, which manages a statically-allocated array of elements of any data type with the following type and non-type template parameters:

T: the type of an element of the managed array, called m_items
C: an unsigned integer representing the capacity of the collection (the size of the managed array); this is the maximum number of items that can be included in the collection.
Your design keeps track of (a) maximum possible number of elements and (b) currently stored number of elements, called as, capacity and size, respectively. When a new item is added to the colection, the size should increse (up to the capacity). The class is to be always instantiated through default constructor.

Your design also keeps track of the smallest item and largest item across all the class objects through class members (aka. type members) as per the following instructions.

Private Class Members

m_smallestItem: an object of type T to store smallest item. This object will be returned by corresponding public static member function. Define it outside the class definition and initialize it to 9999.

m_largestItem: An object of Type T to store largest item. This object will be returned by corresponding public static member function. Define it outside the class definition and initialize it to -9999.

Protected Instance Members

setSmallestItem(): a modifier to receive an object of type T, as unmodifiable reference. It sets m_smallestItem to the received object if the received object is smaller than it.

setLargestItem(): a modifier to receive an object of type T, as unmodifiable reference. It sets m_largestItem to the received object if the received object is larger than it.

Public Class Members

T getSmallestItem(): returns the current smallest item stored in the class attribute.
T getLargestItem(): returns the current largest item stored in the class attribute.
*/
