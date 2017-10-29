#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define p(n) printf("%d",&n)
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
int a[1000005];
vector<double>v;
set<double>se;
int main()
{
        int i,j,k,l,m,n,t,r,cnt;
        int flag;
        ll ans,an;
        cin >> n;
        for(i = 0;i < n;i++){
                sc(a[i]);
        }
	if(n == 3){
		if(((double)(a[1]-a[0])) == ((double)(a[2]-a[0]))/(2)){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
		return 0;
	}
	if(n == 4){
		for(k = 1;k < 4;k++){
			se.clear();
			se.insert(((double)(a[k]-a[0]))/(k));
//		cout << *(se.begin()) << endl;
		cnt = 0;
		int flag3 = 0;
		for(i = 0;i < n;i++){
                        flag = 0;
                        for(j = 0;j < n;j++){
                                if(i == j){
                                        continue;
                                }
                                if(se.find(((double)(a[i]-a[j]))/(i-j)) != se.end()){
                                        flag = 1;
					break;
                                }
				else{
					flag3 = 1;
				}
                        }
                        if(flag == 0){
                                cnt++;
                        }
                }
//		cout << cnt << endl;
		if(cnt <= 1 && flag3 == 1){
                                cout << "Yes" << endl;
			return 0;
                }
		}
	}
	se.clear();
	for(j = 0;j < n;j++){
		v.clear();
		for(i = j+1;i < n;i++){
			v.pb(((double)(a[j]-a[i]))/(j-i));
		}
		sort(v.begin(),v.end());
		cnt = 0;
		for(i = 1;i < v.size();i++){
			if(v[i] == v[i-1]){
				se.insert(v[i]);
			}
		}
	}
//	cout << se.size() << endl;
	if(se.size() >= 2 || se.size() == 0){
		cout << "No" << endl;
	}
	else{
		cnt = 0;
		int flag2 = 0;
//		cout << *(se.begin()) << endl;
		for(i = 0;i < n;i++){
			flag = 0;
			for(j = 0;j < n;j++){
				if(i == j){
					continue;
				}
				if(se.find(((double)(a[i]-a[j]))/(i-j)) != se.end()){
					flag = 1;
					break;
				}
				else{
					flag2 = 1;
				}
			}
			if(flag == 0){
				cnt++;
			}
		}
//		cout << cnt << endl;
			if(cnt <= 1 && flag2 == 1){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
/*		if(se.size() == 2){
			if(cnt == 0){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}*/
	}
}
