"use strict";(self.webpackChunklightning_docs=self.webpackChunklightning_docs||[]).push([[42],{5693:(e,n,r)=>{r.r(n),r.d(n,{assets:()=>d,contentTitle:()=>l,default:()=>p,frontMatter:()=>o,metadata:()=>c,toc:()=>h});var s=r(4848),t=r(8453),i=r(1470),a=r(9365);const o={sidebar_label:"Programming the Driver period",sidebar_position:2},l="Programming the Driver period",c={id:"Tutorials/Driver_period_examples",title:"Programming the Driver period",description:"In Head-to-Head Matches, two (2) Alliances\u2014one (1) \u201cred\u201d and one (1) \u201cblue\u201d\u2014composed of two (2)",source:"@site/docs/Tutorials/Driver_period_examples.md",sourceDirName:"Tutorials",slug:"/Tutorials/Driver_period_examples",permalink:"/Lightninglib/docs/Tutorials/Driver_period_examples",draft:!1,unlisted:!1,editUrl:"https://github.com/HectorAlonso18/Lightninglib/tree/main/docs/Tutorials/Driver_period_examples.md",tags:[],version:"current",sidebarPosition:2,frontMatter:{sidebar_label:"Programming the Driver period",sidebar_position:2},sidebar:"tutorialSidebar",previous:{title:"Declaring your chassis",permalink:"/Lightninglib/docs/Tutorials/Declaring_your_chassis"},next:{title:"Programming the autonomous routine",permalink:"/Lightninglib/docs/Tutorials/Autonomous_Routines_examples"}},d={},h=[{value:"Tank",id:"tank",level:2},{value:"Coding",id:"coding",level:3},{value:"Arcade",id:"arcade",level:2},{value:"Left Arcade",id:"left-arcade",level:3},{value:"Right Arcade",id:"right-arcade",level:3},{value:"Double Arcade",id:"double-arcade",level:3},{value:"Adding rates to arcade configurations",id:"adding-rates-to-arcade-configurations",level:2},{value:"Examples",id:"examples",level:3},{value:"Arcade with exponential",id:"arcade-with-exponential",level:2},{value:"Well and how i use it \ud83e\udd14?",id:"well-and-how-i-use-it-",level:3},{value:"Function prototype",id:"function-prototype",level:4},{value:"Examples",id:"examples-1",level:4},{value:"Ready to drive! \ud83c\udfce\ufe0f",id:"ready-to-drive-\ufe0f",level:2}];function u(e){const n={a:"a",admonition:"admonition",annotation:"annotation",blockquote:"blockquote",code:"code",h1:"h1",h2:"h2",h3:"h3",h4:"h4",hr:"hr",img:"img",li:"li",math:"math",mfrac:"mfrac",mi:"mi",mn:"mn",mo:"mo",mrow:"mrow",msup:"msup",p:"p",pre:"pre",semantics:"semantics",span:"span",strong:"strong",table:"table",tbody:"tbody",td:"td",th:"th",thead:"thead",tr:"tr",ul:"ul",...(0,t.R)(),...e.components};return(0,s.jsxs)(s.Fragment,{children:[(0,s.jsx)(n.h1,{id:"programming-the-driver-period",children:"Programming the Driver period"}),"\n",(0,s.jsxs)(n.blockquote,{children:["\n",(0,s.jsxs)(n.p,{children:["In Head-to-Head Matches, two (2) Alliances\u2014one (1) \u201cred\u201d and one (1) \u201cblue\u201d\u2014composed of two (2)\r\nTeams each, compete in Matches consisting of a fifteen (15) second Autonomous Period followed by a\r\none minute and forty-five second (1:45) ",(0,s.jsx)(n.strong,{children:"Driver Controlled Period"}),"."]}),"\n"]}),"\n",(0,s.jsxs)(n.p,{children:["The ",(0,s.jsx)(n.strong,{children:"Driver Controlled Period"})," is one of the most important aspects in VEX. For that reason, Lightning provides the ability to easily program the driver period for your drivetrain using various configurations that can help you."]}),"\n",(0,s.jsx)(n.p,{children:"In this tutorial, you will learn how to program the driver period using Lightning."}),"\n",(0,s.jsxs)(n.h1,{id:"ensure-you-have-declared-your-drive-train",children:["Ensure you have declared your ",(0,s.jsx)(n.strong,{children:"drive train"})]}),"\n",(0,s.jsxs)(n.p,{children:["You are not sure to how declare your chassis?, check the ",(0,s.jsx)(n.a,{href:"/docs/Tutorials/Declaring_your_chassis",children:"Declaring your chassis tutorial."})]}),"\n",(0,s.jsxs)(n.p,{children:["Your chassis declaration needs to be ",(0,s.jsx)(n.strong,{children:"global"}),". This means that each function can interact with your chassis. The easiest way to do this is to make your chassis declaration at the top of the ",(0,s.jsx)(n.code,{children:"main.cpp"})," file."]}),"\n",(0,s.jsxs)(n.p,{children:["You need more information about ",(0,s.jsx)(n.strong,{children:"Global Variables"}),"? check ",(0,s.jsx)(n.a,{href:"https://www.geeksforgeeks.org/cpp-global-variables/",children:"this"}),"\r\nfor more details."]}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'title="main.cpp"',children:'#include "main.h"\r\n//Here is your drive-train \r\n//Declaring a simple drive train\r\nlightning::TankChassis my_chassis( \r\n //Odometry configuration\r\nlightning::tank_odom_e_t::ADI_ONE_ODOM,\r\n//Declaration of drivetrain motors\r\n{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)\r\n{20,19,18,17},    //Right side ports (using a negative number will reverse it!)\r\n5,   //IMU port \r\npros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? \r\n3.25, //Wheel Diameter\r\n1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)\r\n); //Forward tracking wheel  diameter\r\n\n'})}),"\n",(0,s.jsx)(n.hr,{}),"\n",(0,s.jsx)(n.p,{children:"Once our chassis is declared it is time to program the driver period."}),"\n",(0,s.jsxs)(n.h1,{id:"program-in-the-opcontrol-function",children:["Program in the ",(0,s.jsx)(n.code,{children:"opcontrol"})," function"]}),"\n",(0,s.jsxs)(n.p,{children:["Inside ",(0,s.jsx)(n.code,{children:"main.cpp"}),",you need to locate the ",(0,s.jsx)(n.code,{children:"opcontrol"})," function. This function is designated for ",(0,s.jsx)(n.strong,{children:"Driver Controlled Period"}),"."]}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:"title: main.cpp {13-18}",children:'#include "main.h"\r\n\r\nvoid initialize() {\r\n}\r\n\r\nvoid disabled() {}\r\n\r\nvoid competition_initialize() {}\r\n\r\nvoid autonomous() {\r\n}\r\n\r\nvoid opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n\r\n  }\r\n}\r\n\n'})}),"\n",(0,s.jsxs)(n.p,{children:["The code that we will program in the ",(0,s.jsx)(n.code,{children:"opcontrol"})," function will act in the ",(0,s.jsx)(n.strong,{children:"Driver Controlled Period"}),"."]}),"\n",(0,s.jsx)(n.h1,{id:"chose-your-driver-configuration",children:"Chose your driver configuration"}),"\n",(0,s.jsx)(n.p,{children:"There are different driver configuration. Choose your favorite!\ud83e\udd73"}),"\n",(0,s.jsx)(n.admonition,{type:"info",children:(0,s.jsxs)(n.p,{children:["Currently, ",(0,s.jsx)(n.strong,{children:"lightning"})," supports only tank-drive chassis."]})}),"\n",(0,s.jsx)(n.h2,{id:"tank",children:"Tank"}),"\n",(0,s.jsxs)(n.p,{children:["It is one of the most common driver configurations. Basically, the ",(0,s.jsx)(n.strong,{children:"left joystick"})," controls the left side of the chassis, while the ",(0,s.jsx)(n.strong,{children:"right joystick"})," controls the right side of the chassis."]}),"\n",(0,s.jsx)(n.h3,{id:"coding",children:"Coding"}),"\n",(0,s.jsxs)(n.p,{children:["Using the ",(0,s.jsx)(n.code,{children:"TANK"})," function, we can add the ",(0,s.jsx)(n.strong,{children:"tank driver"})," configuration to our robot."]}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{5} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n\r\n   my_chassis.tank(master); \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\r\n\n"})}),"\n",(0,s.jsx)(n.p,{children:"As a result, we could control our robot using the tank configuration."}),"\n",(0,s.jsx)(n.hr,{}),"\n",(0,s.jsx)(n.h2,{id:"arcade",children:"Arcade"}),"\n",(0,s.jsxs)(n.p,{children:["With the ",(0,s.jsx)(n.code,{children:"ARCADE"})," configuration, you can control the entire chassis using just ",(0,s.jsx)(n.strong,{children:"one"})," joystick."]}),"\n",(0,s.jsx)(n.h3,{id:"left-arcade",children:"Left Arcade"}),"\n",(0,s.jsx)(n.p,{children:"In this configuration, you can control the chassis using the left joystick."}),"\n",(0,s.jsxs)(n.p,{children:["To add the left configuration, you just need to use the ",(0,s.jsx)(n.code,{children:"arcade()"})," function, passing the first parameter."]}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade(master);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})}),"\n",(0,s.jsx)(n.p,{children:"However, you can specify the configuration using the same function."}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade(master,E_TANK_OP_ARCADE_LEFT);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})}),"\n",(0,s.jsx)(n.hr,{}),"\n",(0,s.jsx)(n.h3,{id:"right-arcade",children:"Right Arcade"}),"\n",(0,s.jsx)(n.p,{children:"In this configuration, you can control the chassis using the right joystick."}),"\n",(0,s.jsxs)(n.p,{children:["To add the left configuration, you just need to use the ",(0,s.jsx)(n.code,{children:"arcade()"})," function as follows:"]}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade(master,E_TANK_OP_ARCADE_RIGHT);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})}),"\n",(0,s.jsx)(n.hr,{}),"\n",(0,s.jsx)(n.h3,{id:"double-arcade",children:"Double Arcade"}),"\n",(0,s.jsx)(n.p,{children:"This configuration allows you to control robot\xb4s forward and backward direction with the left joystick\xb4s Y-axis, and control the turning direciton with the right right joystick\xb4s X-axis."}),"\n",(0,s.jsx)(n.admonition,{type:"note",children:(0,s.jsx)(n.p,{children:"Although you can't control the chassis using just one joystick with the double arcade configuration, it is still considered an arcade configuration in the library for practice purposes."})}),"\n",(0,s.jsxs)(n.p,{children:["To add the double configuration, you just need to use the ",(0,s.jsx)(n.code,{children:"arcade()"})," function as follows:"]}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade(master,E_TANK_OP_ARCADE_DOUBLE);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})}),"\n",(0,s.jsx)(n.hr,{}),"\n",(0,s.jsx)(n.h2,{id:"adding-rates-to-arcade-configurations",children:"Adding rates to arcade configurations"}),"\n",(0,s.jsx)(n.p,{children:"When the robot moves too quickly, controlling the chassis can become challenging. To address this, you can adjust the rates to modify the joystick output, which will help slow down the robot."}),"\n",(0,s.jsx)(n.p,{children:"For instance, you might want to reduce the sensitivity for turning while maintaining the same output for forward and backward movement."}),"\n",(0,s.jsxs)(n.p,{children:["This feature can be added to the differents arcade configurations using the ",(0,s.jsx)(n.code,{children:"arcade"})," function with all the parameters."]}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",children:"void arcade(pros::Controller& control, \r\n    const lightning::tank_op_arcade_e_t arcade = lightning::E_TANK_OP_ARCADE_LEFT ,\r\n    const float power_rate=1, const float turn_rate=1); \n"})}),"\n",(0,s.jsx)(n.p,{children:"Where:"}),"\n",(0,s.jsxs)(n.table,{children:[(0,s.jsx)(n.thead,{children:(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.th,{children:"Parameters"}),(0,s.jsx)(n.th,{})]})}),(0,s.jsxs)(n.tbody,{children:[(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.td,{children:(0,s.jsx)(n.code,{children:"control"})}),(0,s.jsx)(n.td,{children:"The control."})]}),(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.td,{children:(0,s.jsx)(n.code,{children:"arcade"})}),(0,s.jsx)(n.td,{children:"The tank_op_arcade_e_t to set for the chassis."})]}),(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.td,{children:(0,s.jsx)(n.code,{children:"power_rate"})}),(0,s.jsx)(n.td,{children:"The rate for the forward and backwards movements (Default is 1)."})]}),(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.td,{children:(0,s.jsx)(n.code,{children:"turn_rate"})}),(0,s.jsx)(n.td,{children:"The rate for the right and left turns (Default is 1)."})]})]})]}),"\n",(0,s.jsx)(n.admonition,{type:"note",children:(0,s.jsxs)(n.p,{children:["If ",(0,s.jsx)(n.code,{children:"power_rate"})," and ",(0,s.jsx)(n.code,{children:"turn_rate"})," are both set to 1, there will be no modification to the output."]})}),"\n",(0,s.jsx)(n.hr,{}),"\n",(0,s.jsx)(n.h3,{id:"examples",children:"Examples"}),"\n",(0,s.jsx)(n.p,{children:"Let's suppose you want to limit the turning power while still using the full power for forward and backward movements. For example, you might decide to use only half of the power for turning."}),"\n",(0,s.jsx)(n.p,{children:"The code will look as follows:"}),"\n",(0,s.jsxs)(i.A,{groupId:"Tutorials_drive_period_examples_adding_rates",defaultValue:"left_arcade",values:[{label:"Left Arcade",value:"left_arcade"},{label:"Right Arcade ",value:"right_arcade"},{label:"Double Arcade",value:"double_arcade"}],children:[(0,s.jsx)(a.A,{value:"left_arcade",children:(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade(master,E_TANK_OP_ARCADE_LEFT,1,.5);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})})}),(0,s.jsx)(a.A,{value:"right_arcade",children:(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade(master,E_TANK_OP_ARCADE_RIGHT,1,.5);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})})}),(0,s.jsx)(a.A,{value:"double_arcade",children:(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade(master,E_TANK_OP_ARCADE_DOUBLE,1,.5);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})})})]}),"\n",(0,s.jsx)(n.h2,{id:"arcade-with-exponential",children:"Arcade with exponential"}),"\n",(0,s.jsxs)(n.p,{children:["You may notice that simply using rates is not the most effective way to control your chassis. This is because applying rates always reduces the robot's velocity. In short, ",(0,s.jsx)(n.strong,{children:"you will never fully utilize your drive-train while using rates"}),"."]}),"\n",(0,s.jsx)(n.p,{children:"However, there is a different approach that allows you to have more precise control while using 100% of your chassis power."}),"\n",(0,s.jsx)(n.p,{children:"To achieve this, we use the following equation:"}),"\n",(0,s.jsx)(n.span,{className:"katex-display",children:(0,s.jsxs)(n.span,{className:"katex",children:[(0,s.jsx)(n.span,{className:"katex-mathml",children:(0,s.jsx)(n.math,{xmlns:"http://www.w3.org/1998/Math/MathML",display:"block",children:(0,s.jsxs)(n.semantics,{children:[(0,s.jsxs)(n.mrow,{children:[(0,s.jsx)(n.mi,{children:"y"}),(0,s.jsx)(n.mo,{children:"="}),(0,s.jsxs)(n.mfrac,{children:[(0,s.jsxs)(n.msup,{children:[(0,s.jsx)(n.mi,{children:"x"}),(0,s.jsx)(n.mi,{children:"n"})]}),(0,s.jsxs)(n.mrow,{children:[(0,s.jsx)(n.mn,{children:"12"}),(0,s.jsxs)(n.msup,{children:[(0,s.jsx)(n.mn,{children:"7"}),(0,s.jsxs)(n.mrow,{children:[(0,s.jsx)(n.mo,{stretchy:"false",children:"("}),(0,s.jsx)(n.mi,{children:"n"}),(0,s.jsx)(n.mo,{children:"\u2212"}),(0,s.jsx)(n.mn,{children:"1"}),(0,s.jsx)(n.mo,{stretchy:"false",children:")"})]})]})]})]})]}),(0,s.jsx)(n.annotation,{encoding:"application/x-tex",children:"y = \\frac{x^{n}}{127^{(n-1)}}"})]})})}),(0,s.jsxs)(n.span,{className:"katex-html","aria-hidden":"true",children:[(0,s.jsxs)(n.span,{className:"base",children:[(0,s.jsx)(n.span,{className:"strut",style:{height:"0.625em",verticalAlign:"-0.1944em"}}),(0,s.jsx)(n.span,{className:"mord mathnormal",style:{marginRight:"0.03588em"},children:"y"}),(0,s.jsx)(n.span,{className:"mspace",style:{marginRight:"0.2778em"}}),(0,s.jsx)(n.span,{className:"mrel",children:"="}),(0,s.jsx)(n.span,{className:"mspace",style:{marginRight:"0.2778em"}})]}),(0,s.jsxs)(n.span,{className:"base",children:[(0,s.jsx)(n.span,{className:"strut",style:{height:"2.0454em",verticalAlign:"-0.704em"}}),(0,s.jsxs)(n.span,{className:"mord",children:[(0,s.jsx)(n.span,{className:"mopen nulldelimiter"}),(0,s.jsx)(n.span,{className:"mfrac",children:(0,s.jsxs)(n.span,{className:"vlist-t vlist-t2",children:[(0,s.jsxs)(n.span,{className:"vlist-r",children:[(0,s.jsxs)(n.span,{className:"vlist",style:{height:"1.3414em"},children:[(0,s.jsxs)(n.span,{style:{top:"-2.296em"},children:[(0,s.jsx)(n.span,{className:"pstrut",style:{height:"3em"}}),(0,s.jsxs)(n.span,{className:"mord",children:[(0,s.jsx)(n.span,{className:"mord",children:"12"}),(0,s.jsxs)(n.span,{className:"mord",children:[(0,s.jsx)(n.span,{className:"mord",children:"7"}),(0,s.jsx)(n.span,{className:"msupsub",children:(0,s.jsx)(n.span,{className:"vlist-t",children:(0,s.jsx)(n.span,{className:"vlist-r",children:(0,s.jsx)(n.span,{className:"vlist",style:{height:"0.814em"},children:(0,s.jsxs)(n.span,{style:{top:"-2.989em",marginRight:"0.05em"},children:[(0,s.jsx)(n.span,{className:"pstrut",style:{height:"2.7em"}}),(0,s.jsx)(n.span,{className:"sizing reset-size6 size3 mtight",children:(0,s.jsxs)(n.span,{className:"mord mtight",children:[(0,s.jsx)(n.span,{className:"mopen mtight",children:"("}),(0,s.jsx)(n.span,{className:"mord mathnormal mtight",children:"n"}),(0,s.jsx)(n.span,{className:"mbin mtight",children:"\u2212"}),(0,s.jsx)(n.span,{className:"mord mtight",children:"1"}),(0,s.jsx)(n.span,{className:"mclose mtight",children:")"})]})})]})})})})})]})]})]}),(0,s.jsxs)(n.span,{style:{top:"-3.23em"},children:[(0,s.jsx)(n.span,{className:"pstrut",style:{height:"3em"}}),(0,s.jsx)(n.span,{className:"frac-line",style:{borderBottomWidth:"0.04em"}})]}),(0,s.jsxs)(n.span,{style:{top:"-3.677em"},children:[(0,s.jsx)(n.span,{className:"pstrut",style:{height:"3em"}}),(0,s.jsx)(n.span,{className:"mord",children:(0,s.jsxs)(n.span,{className:"mord",children:[(0,s.jsx)(n.span,{className:"mord mathnormal",children:"x"}),(0,s.jsx)(n.span,{className:"msupsub",children:(0,s.jsx)(n.span,{className:"vlist-t",children:(0,s.jsx)(n.span,{className:"vlist-r",children:(0,s.jsx)(n.span,{className:"vlist",style:{height:"0.6644em"},children:(0,s.jsxs)(n.span,{style:{top:"-3.063em",marginRight:"0.05em"},children:[(0,s.jsx)(n.span,{className:"pstrut",style:{height:"2.7em"}}),(0,s.jsx)(n.span,{className:"sizing reset-size6 size3 mtight",children:(0,s.jsx)(n.span,{className:"mord mtight",children:(0,s.jsx)(n.span,{className:"mord mathnormal mtight",children:"n"})})})]})})})})})]})})]})]}),(0,s.jsx)(n.span,{className:"vlist-s",children:"\u200b"})]}),(0,s.jsx)(n.span,{className:"vlist-r",children:(0,s.jsx)(n.span,{className:"vlist",style:{height:"0.704em"},children:(0,s.jsx)(n.span,{})})})]})}),(0,s.jsx)(n.span,{className:"mclose nulldelimiter"})]})]})]})]})}),"\n",(0,s.jsx)(n.p,{children:"This function smooths the joystick input based on a specified exponent and maximum value. The smoothing function adjusts the joystick value to create a more gradual response."}),"\n",(0,s.jsxs)(n.p,{children:["If we plot the equation\xb4s output, we get this:\r\n",(0,s.jsx)(n.img,{alt:"smoothing_plot",src:r(3910).A+"",width:"1561",height:"858"})]}),"\n",(0,s.jsx)(n.p,{children:"You may notice that as we increase the exponent, the output becomes smoother. Additionally, if the exponent is an even number, the output function will be purely positive. However, don't worry; in the template, you can use odd or even numbers without any issues!"}),"\n",(0,s.jsxs)(n.p,{children:["You can see more information about this equation ",(0,s.jsx)(n.a,{href:"https://www.vexforum.com/t/what-do-you-think-is-a-more-efficient-way-to-drive-your-robot/64857/42?u=hector_a",children:"here."})]}),"\n",(0,s.jsxs)(n.p,{children:["Also thanks to ",(0,s.jsx)(n.a,{href:"https://www.vexforum.com/u/_Colossus",children:"_Colossus"})," for providing valuable information!"]}),"\n",(0,s.jsx)(n.h3,{id:"well-and-how-i-use-it-",children:"Well and how i use it \ud83e\udd14?"}),"\n",(0,s.jsxs)(n.p,{children:["Easy, just use ",(0,s.jsx)(n.code,{children:"arcade_exponential()"}),"!."]}),"\n",(0,s.jsx)(n.h4,{id:"function-prototype",children:"Function prototype"}),"\n",(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'title="main.cpp"',children:"void arcade_exponential(pros::Controller &control,\r\n                                     const lightning::tank_op_arcade_e_t arcade,\r\n                                     int n_x,\r\n                                     int n_y)\n"})}),"\n",(0,s.jsx)(n.p,{children:"Where:"}),"\n",(0,s.jsxs)(n.table,{children:[(0,s.jsx)(n.thead,{children:(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.th,{children:"Parameters"}),(0,s.jsx)(n.th,{})]})}),(0,s.jsxs)(n.tbody,{children:[(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.td,{children:(0,s.jsx)(n.code,{children:"control"})}),(0,s.jsx)(n.td,{children:"The control."})]}),(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.td,{children:(0,s.jsx)(n.code,{children:"arcade"})}),(0,s.jsx)(n.td,{children:"The tank_op_arcade_e_t to set for the chassis."})]}),(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.td,{children:(0,s.jsx)(n.code,{children:"n_x"})}),(0,s.jsx)(n.td,{children:"The exponential for the joystick x axis."})]}),(0,s.jsxs)(n.tr,{children:[(0,s.jsx)(n.td,{children:(0,s.jsx)(n.code,{children:"n_y"})}),(0,s.jsx)(n.td,{children:"The exponential for the joystick y axis."})]})]})]}),"\n",(0,s.jsx)(n.hr,{}),"\n",(0,s.jsxs)(n.p,{children:["With that established, in this function you can set an arcade configuration and then select the exponential for each movement(turns or backward-forward). For example, if you want smoother output from turns , you should increase ",(0,s.jsx)(n.code,{children:"n_x"}),", and if you want to increase the smoothing for forward and backward movement you have to increase ",(0,s.jsx)(n.code,{children:"n_y"}),"."]}),"\n",(0,s.jsx)(n.admonition,{type:"note",children:(0,s.jsxs)(n.p,{children:["If you want a normal output, set the corresponding exponent (",(0,s.jsx)(n.code,{children:"n_x"})," or ",(0,s.jsx)(n.code,{children:"n_y"}),") to ",(0,s.jsx)(n.strong,{children:"1"}),"."]})}),"\n",(0,s.jsx)(n.h4,{id:"examples-1",children:"Examples"}),"\n",(0,s.jsx)(n.p,{children:"Lets suppose that we want a smoother output for turns."}),"\n",(0,s.jsxs)(i.A,{groupId:"Tutorials_drive_period_examples_adding_rates",defaultValue:"left_arcade",values:[{label:"Left Arcade",value:"left_arcade"},{label:"Right Arcade ",value:"right_arcade"},{label:"Double Arcade",value:"double_arcade"}],children:[(0,s.jsx)(a.A,{value:"left_arcade",children:(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade_exponential(master,E_TANK_OP_ARCADE_LEFT,3,1);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\r\n\n"})})}),(0,s.jsx)(a.A,{value:"right_arcade",children:(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade_exponential(master,E_TANK_OP_ARCADE_RIGHT,3,1);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})})}),(0,s.jsx)(a.A,{value:"double_arcade",children:(0,s.jsx)(n.pre,{children:(0,s.jsx)(n.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void opcontrol() {\r\n  pros::Controller master(pros::E_CONTROLLER_MASTER);\r\n  while (true) {\r\n   my_chassis.arcade_exponential(master,E_TANK_OP_ARCADE_DOUBLE,3,1);  \r\n\r\n   pros::delay(lightning::util::DELAY_TIME); \r\n  }\r\n}\n"})})})]}),"\n",(0,s.jsx)(n.hr,{}),"\n",(0,s.jsx)(n.h2,{id:"ready-to-drive-\ufe0f",children:"Ready to drive! \ud83c\udfce\ufe0f"}),"\n",(0,s.jsx)(n.p,{children:"Congratulations, with this guide you now are able to do:"}),"\n",(0,s.jsxs)(n.ul,{children:["\n",(0,s.jsx)(n.li,{children:"Programing the driver period."}),"\n",(0,s.jsx)(n.li,{children:"Use tank configuration."}),"\n",(0,s.jsx)(n.li,{children:"Use different arcade configurations."}),"\n",(0,s.jsx)(n.li,{children:"Use an exponential method to smooth your joystick output for more control."}),"\n"]})]})}function p(e={}){const{wrapper:n}={...(0,t.R)(),...e.components};return n?(0,s.jsx)(n,{...e,children:(0,s.jsx)(u,{...e})}):u(e)}},9365:(e,n,r)=>{r.d(n,{A:()=>a});r(6540);var s=r(4164);const t={tabItem:"tabItem_Ymn6"};var i=r(4848);function a(e){let{children:n,hidden:r,className:a}=e;return(0,i.jsx)("div",{role:"tabpanel",className:(0,s.A)(t.tabItem,a),hidden:r,children:n})}},1470:(e,n,r)=>{r.d(n,{A:()=>b});var s=r(6540),t=r(4164),i=r(3104),a=r(6347),o=r(205),l=r(7485),c=r(1682),d=r(679);function h(e){return s.Children.toArray(e).filter((e=>"\n"!==e)).map((e=>{if(!e||(0,s.isValidElement)(e)&&function(e){const{props:n}=e;return!!n&&"object"==typeof n&&"value"in n}(e))return e;throw new Error(`Docusaurus error: Bad <Tabs> child <${"string"==typeof e.type?e.type:e.type.name}>: all children of the <Tabs> component should be <TabItem>, and every <TabItem> should have a unique "value" prop.`)}))?.filter(Boolean)??[]}function u(e){const{values:n,children:r}=e;return(0,s.useMemo)((()=>{const e=n??function(e){return h(e).map((e=>{let{props:{value:n,label:r,attributes:s,default:t}}=e;return{value:n,label:r,attributes:s,default:t}}))}(r);return function(e){const n=(0,c.X)(e,((e,n)=>e.value===n.value));if(n.length>0)throw new Error(`Docusaurus error: Duplicate values "${n.map((e=>e.value)).join(", ")}" found in <Tabs>. Every value needs to be unique.`)}(e),e}),[n,r])}function p(e){let{value:n,tabValues:r}=e;return r.some((e=>e.value===n))}function m(e){let{queryString:n=!1,groupId:r}=e;const t=(0,a.W6)(),i=function(e){let{queryString:n=!1,groupId:r}=e;if("string"==typeof n)return n;if(!1===n)return null;if(!0===n&&!r)throw new Error('Docusaurus error: The <Tabs> component groupId prop is required if queryString=true, because this value is used as the search param name. You can also provide an explicit value such as queryString="my-search-param".');return r??null}({queryString:n,groupId:r});return[(0,l.aZ)(i),(0,s.useCallback)((e=>{if(!i)return;const n=new URLSearchParams(t.location.search);n.set(i,e),t.replace({...t.location,search:n.toString()})}),[i,t])]}function x(e){const{defaultValue:n,queryString:r=!1,groupId:t}=e,i=u(e),[a,l]=(0,s.useState)((()=>function(e){let{defaultValue:n,tabValues:r}=e;if(0===r.length)throw new Error("Docusaurus error: the <Tabs> component requires at least one <TabItem> children component");if(n){if(!p({value:n,tabValues:r}))throw new Error(`Docusaurus error: The <Tabs> has a defaultValue "${n}" but none of its children has the corresponding value. Available values are: ${r.map((e=>e.value)).join(", ")}. If you intend to show no default tab, use defaultValue={null} instead.`);return n}const s=r.find((e=>e.default))??r[0];if(!s)throw new Error("Unexpected error: 0 tabValues");return s.value}({defaultValue:n,tabValues:i}))),[c,h]=m({queryString:r,groupId:t}),[x,g]=function(e){let{groupId:n}=e;const r=function(e){return e?`docusaurus.tab.${e}`:null}(n),[t,i]=(0,d.Dv)(r);return[t,(0,s.useCallback)((e=>{r&&i.set(e)}),[r,i])]}({groupId:t}),j=(()=>{const e=c??x;return p({value:e,tabValues:i})?e:null})();(0,o.A)((()=>{j&&l(j)}),[j]);return{selectedValue:a,selectValue:(0,s.useCallback)((e=>{if(!p({value:e,tabValues:i}))throw new Error(`Can't select invalid tab value=${e}`);l(e),h(e),g(e)}),[h,g,i]),tabValues:i}}var g=r(2303);const j={tabList:"tabList__CuJ",tabItem:"tabItem_LNqP"};var f=r(4848);function v(e){let{className:n,block:r,selectedValue:s,selectValue:a,tabValues:o}=e;const l=[],{blockElementScrollPositionUntilNextRender:c}=(0,i.a_)(),d=e=>{const n=e.currentTarget,r=l.indexOf(n),t=o[r].value;t!==s&&(c(n),a(t))},h=e=>{let n=null;switch(e.key){case"Enter":d(e);break;case"ArrowRight":{const r=l.indexOf(e.currentTarget)+1;n=l[r]??l[0];break}case"ArrowLeft":{const r=l.indexOf(e.currentTarget)-1;n=l[r]??l[l.length-1];break}}n?.focus()};return(0,f.jsx)("ul",{role:"tablist","aria-orientation":"horizontal",className:(0,t.A)("tabs",{"tabs--block":r},n),children:o.map((e=>{let{value:n,label:r,attributes:i}=e;return(0,f.jsx)("li",{role:"tab",tabIndex:s===n?0:-1,"aria-selected":s===n,ref:e=>l.push(e),onKeyDown:h,onClick:d,...i,className:(0,t.A)("tabs__item",j.tabItem,i?.className,{"tabs__item--active":s===n}),children:r??n},n)}))})}function _(e){let{lazy:n,children:r,selectedValue:t}=e;const i=(Array.isArray(r)?r:[r]).filter(Boolean);if(n){const e=i.find((e=>e.props.value===t));return e?(0,s.cloneElement)(e,{className:"margin-top--md"}):null}return(0,f.jsx)("div",{className:"margin-top--md",children:i.map(((e,n)=>(0,s.cloneElement)(e,{key:n,hidden:e.props.value!==t})))})}function y(e){const n=x(e);return(0,f.jsxs)("div",{className:(0,t.A)("tabs-container",j.tabList),children:[(0,f.jsx)(v,{...n,...e}),(0,f.jsx)(_,{...n,...e})]})}function b(e){const n=(0,g.A)();return(0,f.jsx)(y,{...e,children:h(e.children)},String(n))}},3910:(e,n,r)=>{r.d(n,{A:()=>s});const s=r.p+"assets/images/smoothing_plot-3dc2f8641f4f8f393a1444bc1eceec35.png"},8453:(e,n,r)=>{r.d(n,{R:()=>a,x:()=>o});var s=r(6540);const t={},i=s.createContext(t);function a(e){const n=s.useContext(i);return s.useMemo((function(){return"function"==typeof e?e(n):{...n,...e}}),[n,e])}function o(e){let n;return n=e.disableParentContext?"function"==typeof e.components?e.components(t):e.components||t:a(e.components),s.createElement(i.Provider,{value:n},e.children)}}}]);