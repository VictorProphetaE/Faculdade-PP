#include<iostream>

using namespace std;
int main()
{
    //matrizes dinâmicas. (AFD, AFN, e alfabetos).
     char **dfa_trans = 0;
     dfa_trans = new char *[3] ;
     for( int i = 0 ; i < 3 ; i++ )
        { dfa_trans[i] = new char[2];
     }
     //função de transição afd.
     char **nfa_trans = 0;
     nfa_trans = new char *[3] ;
     for( int i = 0 ; i < 3 ; i++ )
        {
            nfa_trans[i] = new char[2];
     }
     //função de transição afn.
     char *dfa_state = 0;
     dfa_state = new char [3] ;
     //estados afd
     char *nfa_state = 0;
     nfa_state = new char [3] ;
     //estados afn
     char *dfa_start = 0;
     dfa_start = new char [3] ;
     //começo estados afd
     char *Alphabet = 0;
     Alphabet = new char [3] ;
     //alfabeto
     // inteiros,chars;
     int i,j,k,n_alphabet,n_nfastate,e=0,c=0,temp=0;
     char nfa_start;
      //inicio programa
      cout<<"Por favor, indique o número de alphabes que você deseja usar:"<<endl;
      cin>>n_alphabet;
      cout<<"Digite alphabets.Nota: e representa epsilon !!"<<endl;
      for (i=0;i<n_alphabet;i++)
            cin>>Alphabet[i];
      cout<<"or favor, indique o número de estados que você precisa para usar:"<<endl;
      cin>>n_nfastate;
      cout<<"Digite o nome de estados:"<<endl;
      for (i=0;i<n_nfastate;i++)
            cin>>nfa_state[i];
      cout<<"Digite seu estado inicial:"<<endl;
      cin>>nfa_start;
      cout<<"Digite * se você não quiser usar um alfabeto !!"<<endl;
      for(j=0;j<n_nfastate;j++)
        {
            cout<<"no estado"<<nfa_state[j];
            for(i=0;i<n_alphabet;i++)
                {
                    cout<<" se alfabeto "<<"'"<<Alphabet[i]<<"'"<<" vai para: ";
                    cin>>nfa_trans[i][j];
                    if(Alphabet[i]=='e' && nfa_trans[i][j]!='*')
                        {
                            e++; dfa_start[e-1]=nfa_state[j];
                    }
                }
        }
        cout<<"****************e= "<<e<<endl;
        for(k=0;k<e;k++)
            {
                if(dfa_start[k]!=nfa_start)
                {
                    c++;
                }
            }
        if(c==e)
        {
            dfa_start[e]=nfa_start;
            e++;
        }
        for(k=0;k<e;k++)
            if(dfa_start[e-1]<dfa_start[k])
            {
                temp=dfa_start[k];
                dfa_start[k]=dfa_start[e-1];
                dfa_start[e-1]=temp;
            }
        cout<<"e= "<<e<<endl;
        cout<<"estados afd"<<endl;
        for(k=0;k<e;k++)
        {
            cout<<dfa_start[k]<<endl;
        }
        cout<<"Sua função de transição afn é a seguinte:"<<endl;
        for(j=0;j<n_nfastate;j++)
        {
            cout<<endl;
            for(i=0;i<n_alphabet;i++)
            {
                cout<<nfa_trans[i][j]<<"	";
            }
            cout<<endl;
        }
        cout<<"afd função de transição:"<<endl;
        for(k=0;k<e;k++)
        {
            for(i=0;i<n_alphabet-1;i++)
            {
                if(Alphabet[i]!='e' && nfa_trans[i][k]=='*')
                {
                    nfa_trans[i][k]=dfa_start[k];
                }
                cout<<"no estado "<<" "<<dfa_start[k]<<" no alfabeto "<<"'"<<Alphabet[i]<<"'"<<" vai para: "<<nfa_trans[i][k]<<endl;
            }
        }
        cout<<endl;
return 0;
}
