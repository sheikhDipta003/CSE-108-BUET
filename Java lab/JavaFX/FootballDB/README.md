
# Football Players Database

This is a javafx project I completed as a Term Project during Level 1 Term 2 while pursuing my undergrad degree @ CSE, BUET.

## Features

- ```players.txt``` is used as the database. It stores the players' information for four clubs. The username and pass are:
   - Arsenal - 111
   - Chelsea - 112
   - Liverpool - 113
   - Manchester City - 114
   - Manchester United - 115
- A club can view all its players, search for them and sort them based on different criteria. For example, *search by player name*, *search by country and club name* and so on.
- A club can add a new player by clicking on the *Add new player* button at the bottom of the screen.
- By clicking the *Auction* button after selecting the row corresponding to a player, A club can auction him/her for a price as written in ```players.txt```. 
- All auctioned players can be viewed by clicking on the *Buy new player* button, click on the *Refresh* button if necessary.
- The purpose of this project is to get idea about Model-view-controller architecture for web/desktop applications and how to implement socket communication in java.


## Tech Stack

**Programming Language:** Java

**Framework:** JavaFX

**IDE:** Intellij IDEA


## Run the project

- Open Intellij IDEA
- Click *New project*
- Select *JavaFX* as the *Generator* from the left pannel
- Fill in the following specs:
  - *Name*: FootballDB
  - *Location*: folder path to save the project files
  - *Language* : Java
  - "Build system* : Maven
  - *Group* : com.sheikhdipta003
  - *JDK*: Choose JDK from the dropdown, for this project I used **Oracle OpenJDK version 17.0.7**
  - click *Next* -> *Create*
- The project will be created at the specified folder. Now, copy and paste the ```src``` folder from this repo as well as the ```players.txt``` file.
- Click *Automatically* for allowing Microsoft Defender Configuration whitelisting.
- Click *skip* for the notification *Maven 'FootballDB' build scripts found'
- On the left pannel of the Intellij screen, right-click on *pom.xml* -> *Add as Maven Project*
- *File* -> *Project Structure*
  - *SDKs* : download or add the JDK
  - *Global libraries* : add the path to the ```lib``` folder of javafx installed from [gluonhq.com](https://gluonhq.com/products/javafx/), I used **javafx-sdk-21.0.5** for running this project
  - Select *Modules* in Project Settings in left pane. Click on the folder in which your Java files (showing file outside of source root) are present. Then Select *Sources* from *Mark as:* option. Apply the same steps for multiple folders (```src/main/java``` and ```src/main/resources```).
- Select ```Main.java```, click *Edit Configurations* -> *Modify Options* -> *Allow multiple instances* and *Modify Options* -> *Add VM options* -> ```--module-path "D:\javafx-sdk-21.0.5\lib" --add-modules javafx.controls,javafx.fxml,javafx.graphics``` (May need to add ```javafx.base``` as well)
- First, run ```server.Server```, then run one or more instances of ```main.Main``` to login as one or more club.
## Project Structure


```bash
C:.
│   FootballDB.iml
│   mvnw
│   mvnw.cmd
│   players.txt
│   pom.xml
|
├───.idea
│   └───libraries
├───.mvn
│   └───wrapper
├───src
│   └───main
│       ├───java
│       │   │   module-info.java
│       │   │
│       │   └───com
│       │       └───sheikhdipta003
│       │           └───footballdb
│       │               ├───club
│       │               ├───controller
│       │               ├───data
│       │               ├───main
│       │               ├───netUtil
│       │               └───server
│       └───resources
│           └───com
│               └───sheikhdipta003
│                   └───footballdb
│                       ├───club_css
│                       └───club_fxml
└───target
    ├───classes
```
## Demo

Insert gif or link to demo


## Author

- [Sheikh Intiser Uddin Dipta](https://www.github.com/sheikhDipta003)


## Acknowledgements

 - [Introductory class lecture on javafx](https://drive.google.com/file/d/1ZZDDhQ09lbbvnm7mnmCtslU4kdIzDRX0/view?usp=sharing)
 - [JavaFx Tutorial For Beginners 1 - Introduction To JavaFx](https://youtu.be/9YrmON6nlEw?si=5YZaQsfVie4x2rv7)



## Fixing runtime exceptions

- [How to fix Exception in Application constructor](https://stackoverflow.com/questions/57166325/how-to-fix-exception-in-application-constructor)
- You may need to change the following settings depending on the *Group* name given while creating the project:
  - ```import``` and ```package``` statements at the beginning of the java files,
  - The file names in ```css_fileMap``` and ```fxml_fileMap``` in the ```main()``` method of ```Main.java```. (REMEMBER THAT THESE FILE NAMES MUST START AS ```/com/sheikhdipta003/footballdb/...```, NOT AS ```com/sheikhdipta003/footballdb/...```),
  - The ```fx:controller``` attributes in the fxml files which contain filepaths to the controller files,
  - Finally, the ```players.txt``` must be put outside the ```src``` folder.