
vector<int> funGame (vector<int> stk) {
   queue<int> q;

   for (int i=0; i<stk.size(); i++){
      q.push(stk[i]);
   }

   vector<int> result;

   int a, b;

   while (!stk.empty() and !q.empty()){
      a = q.front();
      b = stk.back();

      if (a > b){
         result.push_back(1);
         stk.pop_back();
      } else if (a < b) {
         result.push_back(2);
         q.pop();
      } else {
         result.push_back(0);
         stk.pop_back();
         q.pop();
      }
   }

   return result;
}

/*

Input:
3
1 2 3

output:
2 2 0

*/
