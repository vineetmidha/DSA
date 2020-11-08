// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/circular-list-8e1319c9/


bool isPrime(int n){
   if (n%2==0 and n!=2) return false;

   for (int i=3; i*i<=n; i+=2){
      if (n%i==0){
         return false;
      }
   }

   return true;
}

void queue_and_stack (vector<int> v) {
   stack<int> s;
   deque<int> dq;

   for (auto i: v){
      if (isPrime(i)){
         dq.push_front(i);
      } else {
         s.push(i);
      }
   }   

   while(!dq.empty()){
      cout<<dq.back()<<" ";
      dq.pop_back();
   }

   cout << endl;

   while(!s.empty()){
      cout<<s.top()<<" ";
      s.pop();
   }
}
