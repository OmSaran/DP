

using namespace std;

void Subject::Attach (observer* o) 
{ 
 _observers.push_back(o); 
} 

void Subject::Detach (observer* o) 
{ 
 int count = _observers.size(); 
 int i; 

 for (i = 0; i < count; i++) { 
   if(_observers[i] == o) 
   break; 
 } 
 if(i < count) 
  _observers.erase(_observers.begin() + i); 

} 

void Subject::Notify () 
{ 
 int count = _observers.size(); 

 for (int i = 0; i < count; i++) 
   (_observers[i])->Update(this); 
}

