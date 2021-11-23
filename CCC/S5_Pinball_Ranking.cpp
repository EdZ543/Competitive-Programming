#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct node{
    int score, rank;
    node *left, *right;

    node(int s){
        score = s;
        rank = 0;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    node *root;

    bst(){
        root = NULL;
    }

    int add(int s){
        int rank = 0;
        if(root == NULL){
            root = new node(s);
        }else{
            node *n = root;
            while(true){
                if(s < n->score){
                    rank += n->rank+1;
                    if(n->left == NULL){
                        n->left = new node(s);
                        return rank;
                    }else{
                        n = n->left;
                    }
                }else{
                    n->rank++;
                    if(n->right == NULL){
                        n->right = new node(s);
                        return rank;
                    }else{
                        n = n->right;
                    }
                }
            }
        }
        return rank;
    }
};

int main(){
    int t; cin >> t;
    double average = 0;
    // bst tree;
    ordered_set tr;
    for(int i=0;i<t;i++){
        int score; cin >> score;
        // average += tree.add(score)+1;
        tr.insert(score);
        average += tr.order_of_key(score)+1;
    }
    average /= t;
    cout << fixed << setprecision(2) << average;
}