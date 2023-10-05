# ⚓ Captain Hook

<div align="center">

   <img width=600px  src="https://user-images.githubusercontent.com/71986226/178690198-9271adbf-d7d2-4728-a762-6ed72c0790f3.png" alt="logo">

  ### Worse than losing is not fighting to win. 🏔️

</div>

<p align="center"> 
    <br> 
</p>

## 📝 Table of Contents

- <a href ="#about"> 📙 Overview</a>
- <a href ="#components"> :money_with_wings: Components & cost</a>
- <a href ="#machines"> ⚙️  Machines</a>
    - <a href ="#arm"> 🦾 Arm</a>
    - <a href ="#food"> 🍲 Food's Machine</a>
    - <a href ="#knife"> 🔪 Knife</a>
    - <a href ="#boiler"> ☕ Boiler</a>
- <a href ="#circuit">💡 Circuit</a>
- <a href ="#integration">🤖 Integration</a>
- <a href ="#contributors"> ✨ Contributors</a>
- <a href ="#license"> 🔒 License</a> 
<hr style="background-color: #4b4c60"></hr>

<a id = "about"></a>

## 📙 Overview 

<ul>
<li>
Captain Hook is robot which makes food and drinks.
 </li>
 <li>
 Captain Hook consists of 4 parts
 <ul>
 <li>Arm</li>
 <li>Food's Machine</li>
 <li>Knife</li>
 <li>Boiler</li>
 </ul>
 </li>
  <li>
 Food Menu
 <ul>
 <li>Rice</li>
 <li>Noodles</li>
 <li>Fried fries</li>
 <li>Salad</li>
 <li>Salad soup</li>
 </ul>
 </li>
  <li>
 Drinks Menu
 <ul>
 <li>Tea</li>
 <li>Nescafe</li>
 </ul>
 </li>
 <li>
 Input for every order

 <br>

 <table>
 <thead>
 <th>Input</th>
 <th>Order</th>

 </thead>
 <tr>
 <td>0</td>
 <td>Fried fries </td>
 </tr>
 <tr>
 <td>1</td>
 <td>Rice </td>
 </tr>
 <tr>
 <td>2</td>
 <td>Noodles </td>
 </tr>
 <tr>
 <td>3</td>
 <td>Salad </td>
 </tr>
 <tr>
 <td>4</td>
 <td>Salad soup </td>
 </tr>
 <tr>
 <td>5</td>
 <td>Tea</td>
 </tr>
 </table>
 </li>
</ul>
<hr style="background-color: #4b4c60"></hr>
<a id = "Components"></a>

## 💸 Components & cost

| Name| Number | Market Cost per Part                                                                                                         |
| --------------  | ------ | ---------------------------------------------------------------------------------------------------------------------------- |
| Arduino Uno    | 1      | 150 EGP                                               |
| 1298 motor driver | 4      | 60 EGP               |
| DC Motor 20kg/cm 12v | 1      | 200 EGP
| Nema 23 Motor | 3 | 30 EGP
| Adapter (12v dc,1A)  | 4 | 25 EGP
| 12v Adapter 3A | 1  | 45 EGP
| Katel | 1 | 35  EGP
|Green Pvc (50cm) | 1 | 10 EGP
|Electric heater | 2 | 100 EGP
| Bearings| 2| 20 EGP
| Tyres rolls (50) | 1 |30 EGP
| Relay 4 channel |1|55 EGP
| 12v dc pump | 1 |100 EGP
| Bluetooth Module | 1|120 EGP
|juice filter | 2 | 20 EGP
|Pvc's elbow | 1| 30 EGP
| Tube (1m) | 1 | 15 EGP|
| White Pvc (1m) | 1 | 100 EGP|

### Total Budget = 1500 L.E
<hr style="background-color: #4b4c60"></hr>

<a id = "Machines"></a>

## 🤖 Machines 

<a id = "Arm"></a>

### 🦾 Arm

<ul>
<li>
Arm is responsible for transferring food to the heater and then deliver it to user.
</li>
<li>
Arm has a hook which allows itto carry the colander which contains the food coming from the food's machine directly or the knife.
</li>
<li>
<a href="https://github.com/EslamAsHhraf/Captain-Hook/blob/main/Arm/Arm.ino">Arm Code.</a>
</li>
<li>
Consists of 2 Stepper motor 
<ul>
<li>
Arm Stepper
</li>
<li>
Base Stepper
</li>
</ul>
</li>
</ul>
<br>
<div align="center">
<img align="center"  width =450px  src="https://user-images.githubusercontent.com/71986226/178992877-fc8c62b3-088c-47c7-9bcd-3f74bb556dce.gif">
</div>
<hr style="background-color: #4b4c60"></hr>
<a id = "Food"></a>

### 🍕 Food's Machine
<ul>
<li>
Food's Machine is responsible for pushing food out of the protective containers above to the Arm, knife or cup according to the order.

</li>
<li>
Food's Machine has a linear actuator (Linear Motion DC Motor) which pushes the food using a piston found at the back of each container.
</li>
<li>
<a href="https://github.com/EslamAsHhraf/Captain-Hook/blob/main/Food's%20Machine/PushingFood.ino">Food's Machine Code.</a>
</li>
<li>
Consists of
<ul>
<li>
Stepper motor 
</li>
<li>
DC linear actuator
</li>
</ul>
</ul>
<br>
<div align="center">
<img align="center"  width =450px  src="https://user-images.githubusercontent.com/71986226/178988843-d09a00c8-603a-441a-a867-d27c83e05173.gif">
</div>
<hr style="background-color: #4b4c60"></hr>
<a id = "Knife"></a>

### 🔪 Knife
<ul>
<li>
Knife is responsible for cutting food like Cucumber and carrots to mini slices.
</li>
<li>
The output goes directly to the colander which is then carried by the arm.
</li>
<li>
Consists of
<ul>
<li>
DC motor 12v (200 kg.cm)
</li>
</ul>
</li>
</ul>
<br>
<div align="center">
<img align="center"  width =200px  src="https://user-images.githubusercontent.com/71986226/178855557-38ff4b30-2cb6-4065-b9d2-181fdb46fc6f.gif">
</div>
<hr style="background-color: #4b4c60"></hr>


<a id = "Boiler"></a>

### 🫖 Boiler
<ul>
<li>
Boiler is responsible of pouring water after boiling into the cup and stirring it inside.
</li>
<li>
<a href="https://github.com/EslamAsHhraf/Captain-Hook/blob/main/Boiler/Boiler.ino">Boiler Code.</a>
</li>
<li>
Consists of
<ul>
<li>
Water pump
</li>
<li>
DC motor for stirring the drink
</li>
</ul>
</ul>
<br>
<div align="center">
<img align="center"  width =300px  src="https://user-images.githubusercontent.com/71986226/178854823-63a01fbc-6791-4a30-b519-387d7ef923a5.png">
</div>



<hr style="background-color: #4b4c60"></hr>

<a id = "Circuit"></a>

## 💡 Circuit 
<ul>
<li>

### <a href="https://github.com/EslamAsHhraf/Captain-Hook/blob/main/Circuit.ckt">Circuit<a>
</li>
</ul>
<br>
<div align="center">
<img align="center"    src="https://user-images.githubusercontent.com/71986226/179020547-0a46f8a5-71e0-4133-bfd6-f575585debe7.png">
</div>

<hr style="background-color: #4b4c60"></hr>

<a id = "Integration"></a>

## 🧠 Integration 

<ul>
<li>We use Pvc tubes to transfer food between machines.</li>
<li><a href="https://github.com/EslamAsHhraf/Captain-Hook/blob/main/Integeration/integeration.ino">Integration code</a</li>
</ul>


## 🥗 Salad
<div  align="center">


<video src="https://user-images.githubusercontent.com/71986226/179088394-ba171cc9-d024-47f4-83aa-8f0853dec0ca.mp4"   >
</video> 

</div>

<hr style="background-color: #4b4c60"></hr>

## 🍚 Rice
<div align="center" >


<video src="https://user-images.githubusercontent.com/71986226/179089465-e3750654-c5b3-4dc3-960c-5359e9732980.mp4" >
</video> 

</div>

<hr style="background-color: #4b4c60"></hr>

<a id ="Contributors"></a>

## 👑 Contributors 
<table align="center">
  <thead >
         <th style="text-align: center;"> Project Manager</th>
        
  </thead>
  <tr>
   <td align="center"><a href="https://github.com/EslamAsHhraf"><img src="https://avatars.githubusercontent.com/u/71986226?v=4" width="150px;" alt=""/><br /><sub><b>Eslam Ashraf</b></sub></a><br /></td>
  </tr>
</table>
<br>
<table align="center">
  <thead >
         <th style="text-align: center;"> Arm Team</th>
         <th style="text-align: center;">Food's Machine team</th>
         <th style="text-align: center;">Knife team</th>
         <th style="text-align: center;">Boiler team</th>
  </thead>
  <tr>
    <td align="center">
    <a href="https://github.com/Abd-ELrahmanHamza" target="_black">
    <img src="https://avatars.githubusercontent.com/u/68310502?v=4" width="150px;" alt="Abdelrahman Mohamed"/>
    <br />
    <sub><b>Abdelrahman Mohamed</b></sub></a>
    </td>
      <td align="center"><a href="https://github.com/abdelazizSalah" ><img src="https://avatars.githubusercontent.com/u/71516308?v=4" width="150px;" alt=""/><br /><sub><b>Abdelaziz Salah</b></sub></a><br />
    </td>
       <td align="center"><a href="https://github.com/EslamAsHhraf"><img src="https://avatars.githubusercontent.com/u/71986226?v=4" width="150px;" alt=""/><br /><sub><b>Eslam Ashraf</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/waleedhesham446" ><img src="https://avatars.githubusercontent.com/u/72695729?v=4" width="150px;" alt=""/><br /><sub><b>Waleed Hesham</b></sub></a><br />
    </td>
  </tr>
  <tr>
 <td align="center">
    <a href="https://github.com/ZiadSheriif" target="_black">
    <img src="https://avatars.githubusercontent.com/u/78238570?v=4" width="150px;" alt="Ziad Sherif"/>
    <br />
    <sub><b>Ziad Sherif</b></sub></a>
    </td>
       <td align="center"><a href="https://github.com/AdhamAliAbdelAal" ><img src="https://avatars.githubusercontent.com/u/83884426?v=4" width="150px;" alt=""/><br /><sub><b>Adham Ali</b></sub></a><br />
    </td>
   <td align="center"><a href="https://github.com/khaHesham"><img src="https://avatars.githubusercontent.com/u/75990647?v=4" width="150px;" alt=""/><br /><sub><b>khaled Hesham</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/AbdelrahmanAshrafMohamedelsayed" ><img src="https://avatars.githubusercontent.com/u/97232730?v=4" width="150px;" alt=""/><br /><sub><b>Abdelrahman Ashraf</b></sub></a><br />
    </td>
  </tr>
  
  <tr>
   <td align="center">
    <a href="https://github.com/ZeyadTarekk" target="_black">
    <img src="https://avatars.githubusercontent.com/u/76125650?v=4" width="150px;" alt="Zeyad Tarek"/>
    <br />
    <sub><b>Zeyad Tarek</b></sub></a>
    </td>
      <td align="center"><a href="https://github.com/mohamedromee12"><img src="https://avatars.githubusercontent.com/u/75943278?v=4" width="150px;" alt=""/><br /><sub><b>Mohamed Romee</b></sub></a><br /></td>
       <td align="center"><a href="https://github.com/MahmoudAbdelhamidAli"><img src="https://avatars.githubusercontent.com/u/87570209?v=4" width="150px;" alt=""/><br /><sub><b>Mahmoud Abdlhamid</b></sub></a><br /></td>
     <td align="center"><a href="https://github.com/MohamedWw" ><img src="https://avatars.githubusercontent.com/u/64079821?v=4" width="150px;" alt=""/><br /><sub><b>Mohamed Walid</b></sub></a><br />
    </td>
  </tr>
  <tr>
   <td align="center">
    <a href="https://github.com/BeshoyMorad" target="_black">
    <img src="https://avatars.githubusercontent.com/u/82404564?v=4" width="150px;" alt="Beshoy Morad"/>
    <br />
    <sub><b>Beshoy Morad</b></sub></a> </td>
      <td align="center"><a href="https://github.com/abdelrahman0123"><img src="https://avatars.githubusercontent.com/u/67989900?v=4" width="150px;" alt=""/><br /><sub><b>Abdelrahman Hamdy</b></sub></a><br /></td>
      <td align="center"><a href="https://github.com/KirollosSamy"><img src="https://avatars.githubusercontent.com/u/67559650?v=4" width="150px;" alt=""/><br /><sub><b>Kirollos Samy</b></sub></a><br /></td>
  </tr>
  <tr>
   <td align="center"><a href="https://github.com/Waer1" ><img src="https://avatars.githubusercontent.com/u/70758177?v=4" width="150px;" alt=""/><br /><sub><b>Waer</b></sub></a><br />
    </td>
      <td align="center"><a href="https://github.com/AbdelrahmanNoaman"><img src="https://avatars.githubusercontent.com/u/76150639?v=4" width="150px;" alt=""/><br /><sub><b>Abdelrahman Noaman</b></sub></a><br /></td>
      <td align="center"><a href="https://github.com/Fathi79"><img src="https://avatars.githubusercontent.com/u/96377553?v=4" width="150px;" alt=""/><br /><sub><b>Abd Elrhman Fathi</b></sub></a><br /></td>
    </td>
  </tr>
  <tr>
   <td align="center"><a href="https://github.com/Amr146?tab=followers" ><img src="https://avatars.githubusercontent.com/u/76057767?v=4" width="150px;" alt=""/><br /><sub><b>
Amr</b></sub></a><br />
    
  </tr>
  
  </table>
  <hr style="background-color: #4b4c60"></hr>

  ### <img align="center" width=70px height=55px src="https://media1.giphy.com/media/iDaCeaKrHhUI1I8e2b/giphy.gif?cid=ecf05e47chfqgmbhlc2e7adg7iw8lnhz8976lmelfw1rf4wk&rid=giphy.gif&ct=s"> Responsibility of Software Integration
  <table >
  <tr>
   <td align="center"><a href="https://github.com/KirollosSamy"><img src="https://avatars.githubusercontent.com/u/67559650?v=4" width="150px;" alt=""/><br /><sub><b>Kirollos Samy</b></sub></a><br /></td>
   <td align="center"><a href="https://github.com/khaHesham"><img src="https://avatars.githubusercontent.com/u/75990647?v=4" width="150px;" alt=""/><br /><sub><b>khaled Hesham</b></sub></a><br /></td>
  </tr>
</table>
<hr style="background-color: #4b4c60"></hr>

  ### <img align="center" width=70px height=70px src="https://media2.giphy.com/media/MXcMYZIUv4TkDb4dbS/giphy.gif?cid=ecf05e472ps3l8zfyfzzw9h5uiu6wzt9lkif0vdos7h4r9h4&rid=giphy.gif&ct=s"> Responsibility of Hardware Integration
  <table >
  <tr>
   <td align="center"><a href="https://github.com/MahmoudAbdelhamidAli"><img src="https://avatars.githubusercontent.com/u/87570209?v=4" width="150px;" alt=""/><br /><sub><b>Mahmoud Abdlhamid</b></sub></a><br /></td>
      <td align="center"><a href="https://github.com/waleedhesham446" ><img src="https://avatars.githubusercontent.com/u/72695729?v=4" width="150px;" alt=""/><br /><sub><b>Waleed Hesham</b></sub></a><br />
    </td>
    <td align="center"><a href="https://github.com/AbdelrahmanAshrafMohamedelsayed" ><img src="https://avatars.githubusercontent.com/u/97232730?v=4" width="150px;" alt=""/><br /><sub><b>Abdelrahman Ashraf</b></sub></a><br />
     <td align="center"><a href="https://github.com/MohamedWw" ><img src="https://avatars.githubusercontent.com/u/64079821?v=4" width="150px;" alt=""/><br /><sub><b>Mohamed Walid</b></sub></a><br />
      <td align="center"><a href="https://github.com/Fathi79"><img src="https://avatars.githubusercontent.com/u/96377553?v=4" width="150px;" alt=""/><br /><sub><b>Abd Elrhman Fathi</b></sub></a><br /></td>
       <td align="center"><a href="https://github.com/EslamAsHhraf"><img src="https://avatars.githubusercontent.com/u/71986226?v=4" width="150px;" alt=""/><br /><sub><b>Eslam Ashraf</b></sub></a><br /></td>
  </tr>
</table>

<hr style="background-color: #4b4c60"></hr>

<a id ="License"></a>

## 🔒 License

> This software is licensed under MIT License, See [License](https://github.com/EslamAsHhraf/Captain-Hook/blob/main/LICENSE) for more information ©EslamAsHhraf.
