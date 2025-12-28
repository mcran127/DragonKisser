# DragonKisser
2025-2026 BYU Game Capstone

On this project, I worked on many facets of the game, moving between blueprints and c++ and did work from debugging, to conversions between c++ and blueprints, to managing architecture.

## Responsibilities

### User Interface

Initially my work on the UI began with the MainUIWidget in blueprints where I did many mock ups of possible UI's we would want and whiteboxed that. Eventually that was moved to another team member, however much of the base code remains the same although subwidgets, assets, and positions have changed. I eventually moved over to the UI for the microgames controlled by many different HUDs which would contain widgets according to best practices. In addition, these widgets were generalized as best as possible for easy reuse between an ever increasing number of microgames.

### Microgames

A current list of the microgames is shows in the microgames folder. In addition we have a CPR microgame which was changed into a singular widget, not made by me although the flow of the game remains the same. I have elected not to include this as while I initially created a different layout of the CPR game, neither the logic, nor the final written code was done by me, only a translation which was later removed. Many of the base classes such as microgamemode and microgame controller were made by me in order to be reused throughout each game. The rhythm games also use templates and object oriented programming to be able to be used between both games regardless of changes or future implementations. Other microgames inherit from base classes and are suited to each individual game to contain the minimum logic required.

### Frontend

The frontend/main menu was created to be independent of the main gameplay loop and is very simple, existing only as a shell to be updated later as it is more needed. Currently, the frontend just acts as a place to play the intro cutscene in tested shipped builds but will likely evolve over time.

### Control

Control is the area that has changed the most and contains the most of others work as well. The game evolved over time so many functions have been added or had their purposes changed. My primary responsibility was creating the HUD and connecting the main widget to it, and the game mode being able to move to and from the microgames and the main level.

#### Short disclaimer.
My official involvement with this project ended at the end of 2025. Production is continuing throughout the winter and possibly further semesters if 2026 so this may not be the most recent code. However, much of this code was created, translated into c++, or both by me.

#### Gameplay as of my leaving

[Playlist of some of the gameplay.](https://youtube.com/playlist?list=PL9kCz4lZXPtBpXhKz2Jk2giC_IbAuGoUW&si=3wn5jkKqCxxJghS5) Other videos of weekly uploads can be viewed on the channel
