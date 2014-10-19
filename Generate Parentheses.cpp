class Solution {
public:
	vector<string> ret;
	vector<string> generateParenthesis(int n) {
		ret.clear();
		int nLeft=0, nRight=0;
		string s;
		rec(n,nLeft,nRight,s);
		return ret;
	}

	/* sol_1: raw idea */
	void rec(int n, int nLeft, int nRight, string s){
		// stop
		if(nRight==n){
			ret.push_back(s);
			return;
		}

		// general
		if(nLeft==nRight){
			string s1=s;
			s1.append(1,'(');
			rec(n,nLeft+1,nRight,s1);
		}else if(nLeft==n){
			string s2=s;
			s2.append(1,')');
			rec(n,nLeft,nRight+1,s2);
		}else{
			// left
			string s1=s;
			s1.append(1,'(');
			rec(n,nLeft+1,nRight,s1);

			// right
			string s2=s;
			s2.append(1,')');
			rec(n,nLeft,nRight+1,s2);
		}
	}

	/* sol_2: simplify the logic */
	void rec_2(int n, int nLeft, int nRight, string s){
		// stop
		if(nRight==n){
			ret.push_back(s);
			return;
		}

		// left: nl<n
		if(nLeft<n){
			string s1=s;
			s1.append(1,'(');
			rec(n,nLeft+1,nRight,s1);
		}

		// right: nr<nl
		if(nRight<nLeft){
			string s2=s;
			s2.append(1,')');
			rec(n,nLeft,nRight+1,s2);
		}
	}
};