1) What you planned on doing for this homework deadline. (Copy + pasted from your previous document)<br />  
This is copied and pasted from previous document: <br />  

When HW2 is due, we will have a detailed class structure.<br />  
When HW3 is due, we will have a working database class.<br />  
When HW4 is due, we will have a working user and superuser class.<br />  
When HW5 is due, we will have a checkpoint/integration for the above 3 done.<br />  
GUI and finished product will be done by the final.<br />  

***OUR GOAL WAS TO HAVE A WORKING DATABASE CLASS BY THIS DUE DATE. Initially, we wanted to use b-tree datastructure for our project for optimal time complexity and the fact that it is used in industry such as SQL and Oracle. However, we ended up using BST instead because it was a data structure we were already familiar with instead of b-tree. ***<br />  

2) What you actually accomplished for this deadline. <br />  
a) Note any differences and explain why they occurred. Prefer honesty over excuses.<br />  
***We have the minimum viable database working. It is able to INSERT values, SEARCH for values, and DELETE values. (In Qt, we will need to integrate these functions to somehow call insert function when hitting the POST button, search function when hitting the GET function, and delete when hitting the DELETE ROW button. *Just keeping in mind for future reference.*) ***

3) What you had planned to do for the next deadline.<br />  
a) Any changes you would like to make to this plan for the next deadline and the
reasoning behind each change.<br />  
***For next deadline, we were planning to have user class and super user class working. The user class will be able to access values in their database and make get requests and post requests. It wil not be able to delete rows. It will need the permission of superuser class which will have permission to do all that. So far, it looks like we will not make any changes for the next deadline.***

***NOTE: We were thinking that for GUI, instead of having get and post button to make requests, we might actually just create a front end registration/login form that just has username and password. Upon registering, it will use post request to write to our database and when logging in, it will use get request to check for username and password and if its in the database it will output successful message. If username/password not in our database then it will simply output error message. Front end aspect for this part is done.  We need to figure out how to connect our database to Qt however for us to deal wiht backend and that will be challenging.*** 

4) Screenshots/gifs of where your app/program/etc is currently at. They don’t have to be exhaustive but they should adequately depict the current state of your project. Embed these for the relevant sections in your .md files. <br />  
BEFORE INSERTION:<br />  
![beforeiinsertion](https://user-images.githubusercontent.com/37274998/97068794-0cd5b600-1588-11eb-8eea-126566373f66.PNG)



AFTER INSERTION:<br />  
![afterinsertion](https://user-images.githubusercontent.com/37274998/97068918-0dbb1780-1589-11eb-965a-0853663e1809.PNG)



SEARCH:<br />
![searching](https://user-images.githubusercontent.com/37274998/97068991-e6187f00-1589-11eb-8e36-45ee5bffd01f.PNG)


BEFORE DELETING A ROW:<br /> 
![beforedelete](https://user-images.githubusercontent.com/37274998/97069022-35f74600-158a-11eb-91d5-d3c0b616ce57.PNG)



AFTER DELETING A ROW:<br />  
![afterdelete](https://user-images.githubusercontent.com/37274998/97069053-650db780-158a-11eb-865f-be677aafc3f1.PNG)






