---
sidebar_label: Math
sidebar_position: 10
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Math 
:::tip
Math functions are built with templates. This means that you can use different types of parameters with these functions, such as `int`, `float`, `double`, etc.
Templates allow these functions to operate with various data types, providing flexibility and reusability in your code. 
:::
## sign()
Sign function.

<Tabs
  groupId="util_functions"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
template <typename T> T sign(const T &num)

```
</TabItem>


<TabItem value="example">

```cpp
bool sign_number; 
sign_number = sign(-5); 

```
</TabItem>

</Tabs>  


