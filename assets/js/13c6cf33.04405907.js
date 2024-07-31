"use strict";(self.webpackChunklightning_docs=self.webpackChunklightning_docs||[]).push([[9141],{6326:(e,n,i)=>{i.r(n),i.d(n,{assets:()=>l,contentTitle:()=>o,default:()=>h,frontMatter:()=>s,metadata:()=>a,toc:()=>c});var t=i(4848),r=i(8453);const s={sidebar_label:"Start Programming",sidebar_position:3},o="Start Programming",a={id:"Getting-started/Start",title:"Start Programming",description:"Once you have already `Lightning` installed, it is time to make some code.",source:"@site/docs/Getting-started/Start.md",sourceDirName:"Getting-started",slug:"/Getting-started/Start",permalink:"/Lightninglib/docs/Getting-started/Start",draft:!1,unlisted:!1,editUrl:"https://github.com/HectorAlonso18/Lightninglib/tree/main/docs/Getting-started/Start.md",tags:[],version:"current",sidebarPosition:3,frontMatter:{sidebar_label:"Start Programming",sidebar_position:3},sidebar:"tutorialSidebar",previous:{title:"Upgrading",permalink:"/Lightninglib/docs/Getting-started/Upgrading"},next:{title:"Documentation \ud83d\udcc4",permalink:"/Lightninglib/docs/category/documentation-"}},l={},c=[{value:"Testing \ud83e\uddea",id:"testing-",level:2},{value:"What is next \ud83e\udd11?",id:"what-is-next-",level:2}];function d(e){const n={a:"a",admonition:"admonition",code:"code",em:"em",h1:"h1",h2:"h2",li:"li",ol:"ol",p:"p",pre:"pre",strong:"strong",ul:"ul",...(0,r.R)(),...e.components};return(0,t.jsxs)(t.Fragment,{children:[(0,t.jsx)(n.h1,{id:"start-programming",children:"Start Programming"}),"\n",(0,t.jsxs)(n.p,{children:["Once you have already ",(0,t.jsx)(n.code,{children:"Lightning"})," installed, it is time to make some code."]}),"\n",(0,t.jsx)(n.admonition,{type:"warning",children:(0,t.jsx)(n.p,{children:"It is necessary to have an IMU sensor in your chassis. If you don't have one, the code will not work."})}),"\n",(0,t.jsx)(n.h2,{id:"testing-",children:"Testing \ud83e\uddea"}),"\n",(0,t.jsxs)(n.p,{children:["The easiest way to test ",(0,t.jsx)(n.code,{children:"Lightning"})," is to run the driver controlled period and see if everything is okay."]}),"\n",(0,t.jsxs)(n.ol,{children:["\n",(0,t.jsxs)(n.li,{children:["Open the ",(0,t.jsx)(n.code,{children:"main.cpp"})," file of your example project."]}),"\n",(0,t.jsxs)(n.li,{children:["Declare your chassis ",(0,t.jsx)(n.a,{href:"/docs/Tutorials/Declaring_your_chassis#without-odometry",children:"without odometry"}),".\r\nYou will notice that at the top of the program, there is a declaration of a chassis that already has odometry. For testing purposes, we will delete this declaration."]}),"\n"]}),"\n",(0,t.jsx)(n.pre,{children:(0,t.jsx)(n.code,{className:"language-cpp",metastring:'title="main.cpp"',children:"//Chassis declaration, for Odometry with a one tracking wheel using ADI, ENCODER \r\nlightning::TankChassis my_chassis( \r\n //Odometry configuration\r\nlightning::tank_odom_e_t::ADI_ONE_ODOM,\r\n//Declaration of drivetrain motors\r\n{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)\r\n{20,19,18,17},    //Right side ports (using a negative number will reverse it!)\r\n5,   //IMU port \r\npros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? \r\n3.25, //Wheel Diameter in inches\r\n1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)\r\n{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!\r\n2.507, //Forward tracking wheel  diameter in inches\r\n1.783, //Distance that exist between the forward tracker and the robot rotation center in inches.\r\n{-1,-1},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!\r\n0, //Sideways tracking wheel  diameter in inches\r\n0); //Forward tracking wheel  diameter in inches\n"})}),"\n",(0,t.jsx)(n.p,{children:"Under this declaration, you will find another declaration that is commented out. This is the declaration we will use for testing. It is a declaration of a chassis without odometry."}),"\n",(0,t.jsx)(n.pre,{children:(0,t.jsx)(n.code,{className:"language-cpp",metastring:'title="main.cpp"',children:"/*DECLARATION OF A CHASSIS WITHOUT ODOMETRY\r\nlightning::TankChassis chassis_without_odometry(\r\n  lightning::tank_odom_e_t::NO_ODOM, //No odometry \r\n  {1,2,3}, //Left side ports (using a negative number will reverse it!)\r\n  {4,5,6}, //Right side ports (using a negative number will reverse it!)\r\n  7, //IMU port \r\n  pros::E_MOTOR_GEAR_BLUE, //Which motor cartride are you using, blue,red,green? \r\n  3.25, //Wheel Diameter in inches\r\n  1.3333 //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)\r\n); */\n"})}),"\n",(0,t.jsx)(n.p,{children:"Uncomment this declaration. You can change the name if desired."}),"\n",(0,t.jsx)(n.pre,{children:(0,t.jsx)(n.code,{className:"language-cpp",metastring:'title="main.cpp"',children:"//DECLARATION OF A CHASSIS WITHOUT ODOMETRY\r\nlightning::TankChassis my_chassis(\r\n  lightning::tank_odom_e_t::NO_ODOM, //No odometry \r\n  {1,2,3}, //Left side ports (using a negative number will reverse it!)\r\n  {4,5,6}, //Right side ports (using a negative number will reverse it!)\r\n  7, //IMU port \r\n  pros::E_MOTOR_GEAR_BLUE, //Which motor cartride are you using, blue,red,green? \r\n  3.25, //Wheel Diameter in inches\r\n  1.3333 //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)\r\n); \n"})}),"\n",(0,t.jsxs)(n.ol,{start:"3",children:["\n",(0,t.jsxs)(n.li,{children:["\n",(0,t.jsx)(n.p,{children:"Introduce your chassis specifications.\r\nFor example, if your chasis have the following specifications:"}),"\n",(0,t.jsxs)(n.p,{children:[(0,t.jsx)(n.strong,{children:"4 motors by side"}),".\r\n",(0,t.jsx)(n.strong,{children:"Left side motors connection:"}),"\r\n",(0,t.jsx)(n.em,{children:"The left motors needs to be reversed, so, the port is negative!"})]}),"\n",(0,t.jsxs)(n.ul,{children:["\n",(0,t.jsxs)(n.li,{children:["LeftMotor_1 -> ",(0,t.jsx)(n.code,{children:"-1"})]}),"\n",(0,t.jsxs)(n.li,{children:["LeftMotor_2 -> ",(0,t.jsx)(n.code,{children:"-2"})]}),"\n",(0,t.jsxs)(n.li,{children:["LeftMotor_3 -> ",(0,t.jsx)(n.code,{children:"-3"})]}),"\n",(0,t.jsxs)(n.li,{children:["LeftMotor_4 -> ",(0,t.jsx)(n.code,{children:"-4"})]}),"\n"]}),"\n",(0,t.jsx)(n.p,{children:(0,t.jsx)(n.strong,{children:"Right side motors connection:"})}),"\n",(0,t.jsxs)(n.ul,{children:["\n",(0,t.jsxs)(n.li,{children:["RightMotor_1 -> ",(0,t.jsx)(n.code,{children:"5"})]}),"\n",(0,t.jsxs)(n.li,{children:["RightMotor_2 -> ",(0,t.jsx)(n.code,{children:"6"})]}),"\n",(0,t.jsxs)(n.li,{children:["RightMotor_3 -> ",(0,t.jsx)(n.code,{children:"7"})]}),"\n",(0,t.jsxs)(n.li,{children:["RightMotor_4 -> ",(0,t.jsx)(n.code,{children:"8"})]}),"\n"]}),"\n",(0,t.jsx)(n.p,{children:(0,t.jsx)(n.strong,{children:"IMU port:"})}),"\n",(0,t.jsxs)(n.ul,{children:["\n",(0,t.jsxs)(n.li,{children:["IMU ->",(0,t.jsx)(n.code,{children:"9"})]}),"\n"]}),"\n",(0,t.jsx)(n.p,{children:(0,t.jsx)(n.strong,{children:"Cartride:"})}),"\n",(0,t.jsxs)(n.ul,{children:["\n",(0,t.jsx)(n.li,{children:"BLUE = 600 RPM"}),"\n"]}),"\n",(0,t.jsx)(n.p,{children:(0,t.jsx)(n.strong,{children:"Wheel diameter:"})}),"\n",(0,t.jsxs)(n.ul,{children:["\n",(0,t.jsxs)(n.li,{children:[(0,t.jsx)(n.code,{children:"3.25"})," inches"]}),"\n"]}),"\n",(0,t.jsx)(n.p,{children:(0,t.jsx)(n.strong,{children:"Gear ratio (Driven/Driving):"})}),"\n",(0,t.jsxs)(n.ul,{children:["\n",(0,t.jsx)(n.li,{children:(0,t.jsx)(n.code,{children:"1.3333"})}),"\n"]}),"\n",(0,t.jsx)(n.p,{children:"With that information, is possible to declare the chassis."}),"\n",(0,t.jsx)(n.pre,{children:(0,t.jsx)(n.code,{className:"language-cpp",metastring:'title="main.cpp"',children:"//DECLARATION OF A CHASSIS WITHOUT ODOMETRY\r\nlightning::TankChassis my_chassis(\r\nlightning::tank_odom_e_t::NO_ODOM, //No odometry \r\n{-1,-2,-3,-4}, //Left side ports (using a negative number will reverse it!)\r\n{5,6,7,8}, //Right side ports (using a negative number will reverse it!)\r\n9, //IMU port \r\npros::E_MOTOR_GEAR_BLUE, //Which motor cartride are you using, blue,red,green? \r\n3.25, //Wheel Diameter in inches\r\n1.3333 //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)\r\n); \n"})}),"\n"]}),"\n",(0,t.jsxs)(n.li,{children:["\n",(0,t.jsx)(n.p,{children:"Run the driver period \ud83c\udfce\ufe0f"}),"\n",(0,t.jsx)(n.p,{children:"When the driver period is running, you will control your chassis using an arcade configuration! If everything runs well, it means that the chassis declaration is correct."}),"\n",(0,t.jsx)(n.admonition,{type:"note",children:(0,t.jsx)(n.p,{children:"You will control the forward and backward direction using the Y-axis of the left joystick, and control the turning using the X-axis of the left joystick."})}),"\n"]}),"\n"]}),"\n",(0,t.jsx)(n.h2,{id:"what-is-next-",children:"What is next \ud83e\udd11?"}),"\n",(0,t.jsx)(n.p,{children:"I would like to encourage everyone to see learning Lightning as a process. As you start using Lightning, following the tutorials, and gradually reading the documentation, you will become proficient and achieve great results."}),"\n",(0,t.jsxs)(n.p,{children:["It is recommended to start reading and implementing the ",(0,t.jsx)(n.a,{href:"/docs/category/tutorials-",children:"Lightning Tutorials"})," and start looking the ",(0,t.jsx)(n.a,{href:"/docs/category/documentation-",children:"Documentation"})," what it is needed."]})]})}function h(e={}){const{wrapper:n}={...(0,r.R)(),...e.components};return n?(0,t.jsx)(n,{...e,children:(0,t.jsx)(d,{...e})}):d(e)}},8453:(e,n,i)=>{i.d(n,{R:()=>o,x:()=>a});var t=i(6540);const r={},s=t.createContext(r);function o(e){const n=t.useContext(s);return t.useMemo((function(){return"function"==typeof e?e(n):{...n,...e}}),[n,e])}function a(e){let n;return n=e.disableParentContext?"function"==typeof e.components?e.components(r):e.components||r:o(e.components),t.createElement(s.Provider,{value:n},e.children)}}}]);