vector<int> & select(){
    vector<int> a(300000);
    vector<int> id(300000);
    for(int i=0;i<300000;i++){
        a[i]= rand()+rand()+rand()+rand()+rand();
        id[i]=i;
    }
    sort(id.begin(),id.end(),[&](int x,int y){ return a[x]<a[y]; });
    id.erase(id.begin()+100000,id.end());
    return id;
}