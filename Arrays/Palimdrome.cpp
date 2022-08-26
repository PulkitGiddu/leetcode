//we can convert this problem into string and then we can solve this 
// and what we can do is by one by one i.e. by reverse
//if some how we have to change our approch so we can do in this manner like 1st break the elements one by one and then then place pointer on first and last 
//then compare it but this way may de little different.

//DO REVERSE THE the whole number 

class Solution {
public:
  bool isPalindrome(int x) {
    
    if ((x < 0)|| (x % 10 == 0 && x != 0)) return false;
    int rev = 0;
    while (rev < x) {
      rev = rev * 10 + (x % 10);
      x /= 10;
    }
    return (rev == x || rev/10 == x);
  }
};
