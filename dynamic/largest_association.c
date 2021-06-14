/*
 * Given a list of item assosiation relationships (i.e, group items to be ordered together), write an algorithm that outputs the largest item association group if two groups have the same number of items then select the group which contains the item that appears first in lexicographic order.
The input to the function consist of an argument itemAssociation, a liist containing pairs of strings representing the items that are ordered together.

Output a list of strings representing the largest item association group, sorted lexicirgaphically

Example
itemAssociation [[Item1,Item2],[Item3, Item4],[Item4,Item5]
output
[Item3,Item4,Item5]
explanation
there is twi item assiciation groups
group1: [item1,item2]
group2:[Item3,Item4,Item5]
In the avialable item associations,group2 has largest association
So the output is [Item3,Item4,Item5]

paris represented as class

class PairString
	{
		String first;
		String second;
		PairString(String first, String second){
			this.first = first;
			this.second = second;
		};
	```
*/

//n = number of items() or n = 100 (max number of items)
//assume n = 5 here;
mat[n+1][n+1] = {0};
  0 1 2 3 4 5
0 0 0 0 0 0 0
1 0 0 1 0 0 0
2 0 0 0 0 0 0
3 0 0 0 0 1 0
4 0 0 0 0 0 1
5 0 0 0 0 0 0


