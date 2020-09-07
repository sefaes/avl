

//NACÝ SEFA GÜRSOY SAKARYA YAZ OKULU VERÝ YAPILARI FÝNAL ÖDEVÝ

#include <iostream>
#include <fstream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))

using namespace std;



struct avl {
   int d;
   struct avl *l;
   struct avl *r;
    string ad;
    string klo;
}*r;

class avl_tree {
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl*);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, int,string,string);
      void show(avl*, int);
      void postorder(avl*);
      avl_tree() {
         r = NULL;
      }
};

int avl_tree::height(avl *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;

   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;

   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);

   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);

   return rr_rotat(parent);
}
avl *avl_tree::balance(avl *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl *r, int v,string ad,string klo) {
   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->ad=ad;
      r->klo=klo;
      r->l = NULL;
      r->r = NULL;
      return r;
   } else if (v< r->d) {
      r->l = insert(r->l, v,ad,klo);
      r = balance(r);
   } else if (v >= r->d) {
      r->r = insert(r->r, v,ad,klo);
      r = balance(r);
   } return r;
}
void avl_tree::show(avl *p, int l) {
   int i;
   if (p != NULL) {
      show(p->r, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->d;
         show(p->l, l + 1);
   }
}


void avl_tree::postorder(avl *t) {

   if (t == NULL)
      return;
      postorder(t ->l);
      postorder(t ->r);


      cout << t->ad<<","<<2020-t->d<<","<<t->klo<<endl;
}

int main(){

avl_tree avl;
 int i=0,toplam;
 string ad,yas,klo;
 ifstream dosya("kisiler.txt");

 if(dosya.is_open()){

    string line;
    int say1;


    while(!dosya.eof()){

       getline(dosya,ad,'#');
        getline(dosya,yas,'#');
         getline(dosya,klo,'\n');

         i += 1;



say1 = stoi(yas);


toplam=2020-say1;


r=avl.insert(r,toplam,ad,klo);






    }

avl.postorder(r);

dosya.close();


 }







}
