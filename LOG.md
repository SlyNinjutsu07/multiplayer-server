# Daily Running Log of this Project's timeline

## 11.3.26

Not the latest update, as I first started this project a few days ago during the halloween weekend.

I first learned the basic multiplayer server architecture through Gabriel Gambetta's [articles](https://gabrielgambetta.com/client-server-game-architecture.html).
I have to say, I absolutely enjoyed reading it because I actually developed an understanding on certain performance tricks are implemented, such as client prediction to avoid the delayed update of values from the server, or entity interpolation where the client draws out the past actions of other players to show motion. Server reconciliation, however, is still a rusty topic for me as it involves the client sending request packets to the server, the server applying these requests one by one, and then sending the updates along with what request was satisfied, to the client. It's quite confusing atm.

I got some of the project directory layout done with the help of asking Gemini and Claude on how to do what and what (such as how on earth I handle packets of data, or how to start a clock for the live game).


