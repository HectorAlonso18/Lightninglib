"use strict";(self.webpackChunklightning_docs=self.webpackChunklightning_docs||[]).push([[9257],{430:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>c,contentTitle:()=>i,default:()=>p,frontMatter:()=>l,metadata:()=>u,toc:()=>d});var r=n(4848),s=n(8453),o=n(1470),a=n(9365);const l={sidebar_label:"Util",sidebar_position:7},i="Util",u={id:"Documentation/util",title:"Util",description:"Functions",source:"@site/docs/Documentation/util.md",sourceDirName:"Documentation",slug:"/Documentation/util",permalink:"/Lightninglib/docs/Documentation/util",draft:!1,unlisted:!1,editUrl:"https://github.com/HectorAlonso18/Lightninglib/tree/main/docs/Documentation/util.md",tags:[],version:"current",sidebarPosition:7,frontMatter:{sidebar_label:"Util",sidebar_position:7},sidebar:"tutorialSidebar",previous:{title:"Pure pursuit",permalink:"/Lightninglib/docs/Documentation/Pure_pursuit"},next:{title:"Tank Chassis",permalink:"/Lightninglib/docs/Documentation/TankChassis"}},c={},d=[{value:"Functions",id:"functions",level:2},{value:"is_reversed()",id:"is_reversed",level:3},{value:"smooth_Joystick_Output()",id:"smooth_joystick_output",level:3}];function h(e){const t={code:"code",h1:"h1",h2:"h2",h3:"h3",hr:"hr",p:"p",pre:"pre",strong:"strong",table:"table",tbody:"tbody",td:"td",th:"th",thead:"thead",tr:"tr",...(0,s.R)(),...e.components};return(0,r.jsxs)(r.Fragment,{children:[(0,r.jsx)(t.h1,{id:"util",children:"Util"}),"\n",(0,r.jsx)(t.h2,{id:"functions",children:"Functions"}),"\n",(0,r.jsx)(t.h3,{id:"is_reversed",children:"is_reversed()"}),"\n",(0,r.jsx)(t.p,{children:"Checks whether a smart port is reversed."}),"\n",(0,r.jsxs)(o.A,{groupId:"util_functions",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Prototype_2",value:"proto_2"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(t.pre,{children:(0,r.jsx)(t.code,{className:"language-cpp",children:"  bool is_reversed(double input); \n"})})}),(0,r.jsx)(a.A,{value:"proto_2",children:(0,r.jsx)(t.pre,{children:(0,r.jsx)(t.code,{className:"language-cpp",children:"  bool is_reversed(int input); \n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(t.pre,{children:(0,r.jsx)(t.code,{className:"language-cpp",children:"   #define INTAKER_PORT\r\n   \r\n   bool port_is_reversed = is_reversed(INTAKER_PORT);     \r\n   \r\n   if(port_is_reversed){\r\n\r\n   }\n"})})})]}),"\n",(0,r.jsxs)(t.table,{children:[(0,r.jsx)(t.thead,{children:(0,r.jsxs)(t.tr,{children:[(0,r.jsx)(t.th,{children:"Parameters"}),(0,r.jsx)(t.th,{})]})}),(0,r.jsx)(t.tbody,{children:(0,r.jsxs)(t.tr,{children:[(0,r.jsx)(t.td,{children:(0,r.jsx)(t.code,{children:"input"})}),(0,r.jsx)(t.td,{children:"A number."})]})})]}),"\n",(0,r.jsxs)(t.p,{children:[(0,r.jsx)(t.strong,{children:"Returns:"})," ",(0,r.jsx)(t.code,{children:"true"})," if the port it is reversed. Or ``false` if the port it not reversed."]}),"\n",(0,r.jsx)(t.hr,{}),"\n",(0,r.jsx)(t.h3,{id:"smooth_joystick_output",children:"smooth_Joystick_Output()"}),"\n",(0,r.jsx)(t.p,{children:"Applies a smoothing function to joystick input values."}),"\n",(0,r.jsx)(t.p,{children:"This function smooths the joystick input based on a specified exponent and maximum value. The smoothing function adjusts the joystick value to create a more gradual response."}),"\n",(0,r.jsxs)(o.A,{groupId:"util_functions",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(t.pre,{children:(0,r.jsx)(t.code,{className:"language-cpp",children:"  float smooth_Joystick_Output(int joystick_value, int exponent, int max_value); \n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(t.pre,{children:(0,r.jsx)(t.code,{className:"language-cpp",children:"void opcontrol(){\r\n    while(1){\r\n    raw_joystick_x = control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X); //raw joystick value\r\n    raw_joystick_y = control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);  //raw joystick value\r\n    \r\n    power = util::smooth_Joystick_Output(raw_joystick_y,n_y); //smooth joystick value\r\n    turn= util::smooth_Joystick_Output(raw_joystick_x, n_x);  //smooth joystick value\r\n    \r\n    left_side.move(power+turn);\r\n    right_side.move(powe-turn); \r\n\r\n    pros::delay(10);\r\n    }\r\n}\n"})})})]}),"\n",(0,r.jsxs)(t.table,{children:[(0,r.jsx)(t.thead,{children:(0,r.jsxs)(t.tr,{children:[(0,r.jsx)(t.th,{children:"Parameters"}),(0,r.jsx)(t.th,{})]})}),(0,r.jsxs)(t.tbody,{children:[(0,r.jsxs)(t.tr,{children:[(0,r.jsx)(t.td,{children:(0,r.jsx)(t.code,{children:"joystick_value"})}),(0,r.jsx)(t.td,{children:"Analog joystick value."})]}),(0,r.jsxs)(t.tr,{children:[(0,r.jsx)(t.td,{children:(0,r.jsx)(t.code,{children:"exponent"})}),(0,r.jsx)(t.td,{children:"The exponent value; a higher exponent provides more smoothing."})]}),(0,r.jsxs)(t.tr,{children:[(0,r.jsx)(t.td,{children:(0,r.jsx)(t.code,{children:"max_value"})}),(0,r.jsx)(t.td,{children:"The maximum value of the joystick. Default value is 127."})]})]})]})]})}function p(e={}){const{wrapper:t}={...(0,s.R)(),...e.components};return t?(0,r.jsx)(t,{...e,children:(0,r.jsx)(h,{...e})}):h(e)}},9365:(e,t,n)=>{n.d(t,{A:()=>a});n(6540);var r=n(4164);const s={tabItem:"tabItem_Ymn6"};var o=n(4848);function a(e){let{children:t,hidden:n,className:a}=e;return(0,o.jsx)("div",{role:"tabpanel",className:(0,r.A)(s.tabItem,a),hidden:n,children:t})}},1470:(e,t,n)=>{n.d(t,{A:()=>y});var r=n(6540),s=n(4164),o=n(3104),a=n(6347),l=n(205),i=n(7485),u=n(1682),c=n(679);function d(e){return r.Children.toArray(e).filter((e=>"\n"!==e)).map((e=>{if(!e||(0,r.isValidElement)(e)&&function(e){const{props:t}=e;return!!t&&"object"==typeof t&&"value"in t}(e))return e;throw new Error(`Docusaurus error: Bad <Tabs> child <${"string"==typeof e.type?e.type:e.type.name}>: all children of the <Tabs> component should be <TabItem>, and every <TabItem> should have a unique "value" prop.`)}))?.filter(Boolean)??[]}function h(e){const{values:t,children:n}=e;return(0,r.useMemo)((()=>{const e=t??function(e){return d(e).map((e=>{let{props:{value:t,label:n,attributes:r,default:s}}=e;return{value:t,label:n,attributes:r,default:s}}))}(n);return function(e){const t=(0,u.X)(e,((e,t)=>e.value===t.value));if(t.length>0)throw new Error(`Docusaurus error: Duplicate values "${t.map((e=>e.value)).join(", ")}" found in <Tabs>. Every value needs to be unique.`)}(e),e}),[t,n])}function p(e){let{value:t,tabValues:n}=e;return n.some((e=>e.value===t))}function m(e){let{queryString:t=!1,groupId:n}=e;const s=(0,a.W6)(),o=function(e){let{queryString:t=!1,groupId:n}=e;if("string"==typeof t)return t;if(!1===t)return null;if(!0===t&&!n)throw new Error('Docusaurus error: The <Tabs> component groupId prop is required if queryString=true, because this value is used as the search param name. You can also provide an explicit value such as queryString="my-search-param".');return n??null}({queryString:t,groupId:n});return[(0,i.aZ)(o),(0,r.useCallback)((e=>{if(!o)return;const t=new URLSearchParams(s.location.search);t.set(o,e),s.replace({...s.location,search:t.toString()})}),[o,s])]}function v(e){const{defaultValue:t,queryString:n=!1,groupId:s}=e,o=h(e),[a,i]=(0,r.useState)((()=>function(e){let{defaultValue:t,tabValues:n}=e;if(0===n.length)throw new Error("Docusaurus error: the <Tabs> component requires at least one <TabItem> children component");if(t){if(!p({value:t,tabValues:n}))throw new Error(`Docusaurus error: The <Tabs> has a defaultValue "${t}" but none of its children has the corresponding value. Available values are: ${n.map((e=>e.value)).join(", ")}. If you intend to show no default tab, use defaultValue={null} instead.`);return t}const r=n.find((e=>e.default))??n[0];if(!r)throw new Error("Unexpected error: 0 tabValues");return r.value}({defaultValue:t,tabValues:o}))),[u,d]=m({queryString:n,groupId:s}),[v,x]=function(e){let{groupId:t}=e;const n=function(e){return e?`docusaurus.tab.${e}`:null}(t),[s,o]=(0,c.Dv)(n);return[s,(0,r.useCallback)((e=>{n&&o.set(e)}),[n,o])]}({groupId:s}),b=(()=>{const e=u??v;return p({value:e,tabValues:o})?e:null})();(0,l.A)((()=>{b&&i(b)}),[b]);return{selectedValue:a,selectValue:(0,r.useCallback)((e=>{if(!p({value:e,tabValues:o}))throw new Error(`Can't select invalid tab value=${e}`);i(e),d(e),x(e)}),[d,x,o]),tabValues:o}}var x=n(2303);const b={tabList:"tabList__CuJ",tabItem:"tabItem_LNqP"};var f=n(4848);function j(e){let{className:t,block:n,selectedValue:r,selectValue:a,tabValues:l}=e;const i=[],{blockElementScrollPositionUntilNextRender:u}=(0,o.a_)(),c=e=>{const t=e.currentTarget,n=i.indexOf(t),s=l[n].value;s!==r&&(u(t),a(s))},d=e=>{let t=null;switch(e.key){case"Enter":c(e);break;case"ArrowRight":{const n=i.indexOf(e.currentTarget)+1;t=i[n]??i[0];break}case"ArrowLeft":{const n=i.indexOf(e.currentTarget)-1;t=i[n]??i[i.length-1];break}}t?.focus()};return(0,f.jsx)("ul",{role:"tablist","aria-orientation":"horizontal",className:(0,s.A)("tabs",{"tabs--block":n},t),children:l.map((e=>{let{value:t,label:n,attributes:o}=e;return(0,f.jsx)("li",{role:"tab",tabIndex:r===t?0:-1,"aria-selected":r===t,ref:e=>i.push(e),onKeyDown:d,onClick:c,...o,className:(0,s.A)("tabs__item",b.tabItem,o?.className,{"tabs__item--active":r===t}),children:n??t},t)}))})}function _(e){let{lazy:t,children:n,selectedValue:s}=e;const o=(Array.isArray(n)?n:[n]).filter(Boolean);if(t){const e=o.find((e=>e.props.value===s));return e?(0,r.cloneElement)(e,{className:"margin-top--md"}):null}return(0,f.jsx)("div",{className:"margin-top--md",children:o.map(((e,t)=>(0,r.cloneElement)(e,{key:t,hidden:e.props.value!==s})))})}function g(e){const t=v(e);return(0,f.jsxs)("div",{className:(0,s.A)("tabs-container",b.tabList),children:[(0,f.jsx)(j,{...t,...e}),(0,f.jsx)(_,{...t,...e})]})}function y(e){const t=(0,x.A)();return(0,f.jsx)(g,{...e,children:d(e.children)},String(t))}},8453:(e,t,n)=>{n.d(t,{R:()=>a,x:()=>l});var r=n(6540);const s={},o=r.createContext(s);function a(e){const t=r.useContext(o);return r.useMemo((function(){return"function"==typeof e?e(t):{...t,...e}}),[t,e])}function l(e){let t;return t=e.disableParentContext?"function"==typeof e.components?e.components(s):e.components||s:a(e.components),r.createElement(o.Provider,{value:t},e.children)}}}]);