#include <iostream>

using namespace std;

class tree{
  public:
    tree* left;
    tree* right;
    int num;

    tree(int i){
      left = NULL;
      right = NULL;
      num = i;
    }

    ~tree(){
      delete left;
      delete right;
    }
};

void insert(tree* root,int i){
  if(root == NULL){
    root = new tree(i);
  }
  if(i < root->num)
    if(root->left == NULL){
      root->left = new tree(i);
    }
    else
      insert(root->left,i);
  else
    if(root->right == NULL){
      root->right = new tree(i);
    }
    else
      insert(root->right,i);
}

int weight(tree* t){
  if(t==NULL)
    return 0;
  return 1+weight(t->left)+weight(t->right);
}

int balance(tree* t){
  if(t== NULL)
    return 0;
  int l = weight(t->left);
  int r = weight(t->right);
  if(l < r){
    tree* temp = t->right;
    tree* parent = t;
    while(temp->left != NULL){
      parent = temp;
      temp = temp->left;
    }
    int lold = t->num;
    t->num = temp->num;
    if(temp == parent->left)
      parent->left = NULL;
    else
      parent->right = NULL;
    delete temp;
    insert(t,lold);
    // Rebalance
    return 1+balance(t->left)+balance(t->right);
  }
  if(l>r+1){
    tree* temp = t->left;
    tree* parent = t;
    while(temp->right != NULL){
      parent = temp;
      temp = temp->right;
    }
    int lold = t->num;
    t->num = temp->num;
    if(temp == parent->left)
      parent->left = NULL;
    else
      parent->right = NULL;
    delete temp;
    insert(t,lold);
    // Rebalance
    return 1+balance(t->left)+balance(t->right);
  }
  else return balance(t->left)+balance(t->right);
}

void inorder(tree* t){
  if(t == NULL)
    return;
  else{
    inorder(t->left);
    cout << " " << t->num << " ";
    inorder(t->right);
  }
}

int main(){
  int noofcases;
  cin >> noofcases;
  for(int j=0;j<noofcases;j++){
    int i;
    cin >> i;
    tree* t1 = new tree(i);
    int count=1;
    while(count > -1){
      cin >> i;
      if(i==0)
        count--;
      else{
        count++;
        insert(t1,i);
      }
    }
    int b;
    cin >> b;
    int noofbalances=0;
    for(int j=0;j<b;j++){
      cin >> i;
      insert(t1,i);
      noofbalances += balance(t1);
    }
    cout << noofbalances << endl;
    delete t1;
  }
  return 0;
}
