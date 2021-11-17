#include <bits/stdc++.h>
using namespace std;

struct node{
    int skill, position;
    node *left, *right, *parent;

    node(int s, int p){
        skill = s;
        position = p;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

struct tourney{
    vector<node*> nodes;
    node *root;

    void init(vector<int> people){
        nodes.push_back(new node(0, 0));

        for(int i=1;i<people.size();i++){
            nodes.push_back(new node(people[i], i));
        }

        queue<node*> rounds;
        for(int i=1;i<nodes.size();i++){
            rounds.push(nodes[i]);
        }

        while(!rounds.empty()){
            node *curA = rounds.front(); rounds.pop(); 
            node *curB = rounds.front(); rounds.pop();

            int nextSkill, nextPos;
            if(curA->skill > curB->skill){
                nextSkill = curA->skill;
                nextPos = curA->position;
            }else{
                nextSkill = curB->skill;
                nextPos = curB->position;
            }

            node *next = new node(nextSkill, nextPos);
            next->left = curA;
            next->right = curB;
            curA->parent = next;
            curB->parent = next;

            rounds.push(next);

            if(rounds.size() == 1){
                root = rounds.front();
                rounds.pop();
            }
        }
    }

    void replace(int oldPos, int newSkill){
        nodes[oldPos]->skill = newSkill;

        node *cur = nodes[oldPos]->parent;
        while(cur != NULL){
            int nextSkill, nextPos;
            if(cur->left->skill > cur->right->skill){
                nextSkill = cur->left->skill;
                nextPos = cur->left->position;
            }else{
                nextSkill = cur->right->skill;
                nextPos = cur->right->position;
            }
            if(nextSkill == cur->skill){
                break;
            }else{
                cur->skill = nextSkill;
                cur->position = nextPos;
                cur = cur->parent;
            }
        }
    }

    int winar(){
        return root->position;
    }

    int numWins(int pos){
        node *cur = nodes[pos]->parent;
        int wins = 0;
        while(cur != NULL && cur->position == pos){
            cur = cur->parent;
            wins++;
        }
        return wins;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> people(pow(2, n)+1);
    for(int i=1;i<=pow(2, n);i++){
        cin >> people[i];
    }
    tourney t;
    t.init(people);

    for(int i=0;i<m;i++){
        char a; cin >> a;
        if(a == 'R'){
            int oldPos, newSkill; cin >> oldPos >> newSkill;
            t.replace(oldPos, newSkill);
        }else if(a == 'W'){
            cout << t.winar() << "\n";
        }else if(a == 'S'){
            int pos; cin >> pos;
            cout << t.numWins(pos) << "\n";
        }
    }
}