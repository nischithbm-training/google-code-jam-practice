#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/* Function Prototypes */
void readLawnPattern();
bool isValidLawnPattern();

void processTestCase();

/* Global Variables */
int T,N,M;
vector< vector<int> > lawnPattern;

int main() {
    scanf("%d", &T);

    int t=0;
    while (t<T) {
        printf("Case #%d: ", ++t);
        processTestCase();        
    }

    return 0;
}

void processTestCase() {
    readLawnPattern();

    printf("%s\n",isValidLawnPattern()?"YES":"NO");
    
    lawnPattern.clear();
}

bool isValidLawnPattern() {
    int R[N];
    int C[M];
    
    for (int i=0;i<N;i++ ) R[i]=0;
    for (int j=0;j<M;j++ ) C[j]=0;

    for (int i=0;i<N;i++ ) {
        for (int j=0;j<M;j++ ) {
            R[i]=max(R[i], lawnPattern[i][j]);
            C[j]=max(C[j], lawnPattern[i][j]);
        }
    }

    bool valid = true;
    for (int i=0;i<N;i++){
		for (int j=0;j<M;j++) {
			if (lawnPattern[i][j] != min(R[i],C[j])) valid = false;
		}
	}

    return valid;
}


void readLawnPattern(){
    int temp;
    
    scanf("%d %d",&N,&M);

    for (int i=0;i<N;i++ ) {
        vector<int> row;
        for (int j=0;j<M;j++ ) {
            scanf(" %d", &temp);
            row.push_back(temp);
        }
        lawnPattern.push_back(row);
    }
}

