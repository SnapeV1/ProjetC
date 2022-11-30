# a C Project

    	We are planning to develop an application that aims to
	to manage the municipal elections.
			
						
		#Objective
	The objective of this project is to set up an application that allows the automation of
	the course of the municipal elections.
	


		#Identification of the actors
	We have identified a number of actors who will interact with this system, and who are :
  - An administrator
  - A polling station agent
  - A voter
  - An observer

    	Each actor has a user space.




#Specification of functional and non-functional requirements

		a) Functional requirements:
	The functional requirements represent the actions that the system must perform.
	Thus this application must cover mainly the following functional needs:
	User management
	- The administrator can add, modify, delete, display and assign a voter to a polling station.

	voter to a polling station. The assignment can be done
	automatically (in the first polling station not complete) or
	manually.
	Elections management
	- The administrator can add, cancel, modify, display an election

	Management of polling stations
	- The administrator can add, modify, delete, display and assign an agent to

	a polling station (in the form of

	Management of the electoral lists + vote
	- A voter can add, modify, delete, display an electoral list.
	Voting: a voter can add a vote

	Management of observers
	- A polling station agent can add, modify or delete an observer

	Claims management
	- An observer can add, modify or delete a complaint




		b) Non-functional requirements
	Our application must meet the following criteria:

	- Authentication: The user of the application must authenticate himself to access his
	access to his space.
	- Ergonomics: the application offers a user-friendly and easy interface.
	-The application respects a certain graphic charter
   Note: if you have teams with less than 6 members,
	the management of complaints and the management of observers are the least priority.

	Entities/structures: talk to students about them to take them into account
	when drawing a sketch of the add-on form

		1. User
	-first and last name
	- CIN
	- Date of birth
	-Login and password
	- Role
	-vote: integer: -1 did not vote, 0 blank vote otherwise list number
	- polling station number to assign a voter to a polling station
	to a polling station or an agent to a polling station

		2. Election
	-Date
	-identifier
	-number of inhabitants
	-number of councillors: automatically calculated
	-Municipality
		3. Polling station:
	-identifier
	-capacity of voters
	-capacity of observers
	-room/ address

	- Id of the polling station agent
		4. Voters List:
	-id
	-orientation (left, right, center)
	-id head list (the voter who added the list)
	In order to simplify the task for the student, we can consider that the list
	is composed of 3 instead of 9
	So the student can make 3 fields (id1, id2, id3) or an array
	of size 3 to store the identifiers of the 3 candidates

		5. Observer:
	- Last name, first name
	- Nationality
	- affiliation: political party, press, host, civil society,world organization
	- gender

		6. Claim :
	- Claim text
	- Claim type :
	- Electoral list claimed
	- Polling station number
