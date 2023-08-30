class Solution {
public:
    int parent[1001];
    int findParOf(int i){
        if(parent[i]==i)
        return i;
        return parent[i] = findParOf(parent[i]);
        
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        memset(parent,-1,sizeof(parent)); // its ur wish to initialize with anything

        unordered_map<string,int>parentOfEmail; // it means eamil belongs to which user
        
        for(int i=0;i<acc.size();i++){
            parent[i]=i; // inititally theprent will be initialise of the form like below
            /* i=>         0 1 2 3
               parent[i]=> 0 1 2 3
            */
            for(int j=1;j<acc[i].size();j++){ // traversing through the email vector of user i
                if(parentOfEmail.find(acc[i][j])!=parentOfEmail.end()){ // ie => this email is already assigned to some user before therefore this user is duplicate
                    int parentOfuser_i = findParOf(i);
                    int parentOfCurrentEmail = findParOf(parentOfEmail[acc[i][j]]);

                    parent[parentOfuser_i] =  parentOfCurrentEmail;
                }else{ // this email is new therefore parent of this email will be parent of user i
                    parentOfEmail[acc[i][j]] = parent[i];
                }
            }
        }

            unordered_map<int,vector<string>>listOfEmail; // vector of string of email for user with int id
            vector<vector<string>> ans;
            for(auto it:parentOfEmail){
                int user = findParOf(it.second);
                auto email = it.first;
                listOfEmail[user].push_back(email);
            }
            for(auto it:listOfEmail){
                int user = it.first;
                vector<string>emails = it.second;
                sort(emails.begin(),emails.end()); // sorting the emails;
                
                emails.insert(emails.begin(),acc[user][0]);// inserting the name of user before the emails
                ans.push_back(emails);
                //acc[user][0] the first elemnet of every vector of string in accounts is name of user
            }
            return ans;
        
    }
};
