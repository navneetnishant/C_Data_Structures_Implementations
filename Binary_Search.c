/*
Binary search

=> Needs a sorted list/array (mandatory) else it fails

=> We divide the array in halfs
and compare the 'val' with middle element

if 'val' is greater than middle element, we divide the 2nd half 
and compare
else if 'val' is less than middle element, we divide the first half
else if 'val' is equal to middle element. we return the mid

=> if 'beg' becomes greater than 'end', the 'val' not found 
in the list

=> Complexity: O(log n)
*/