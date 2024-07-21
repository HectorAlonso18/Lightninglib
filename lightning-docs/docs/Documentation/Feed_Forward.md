---
sidebar_label: Feed Forward
sidebar_position: 2
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# FeedForward

## Constructors

### FeedForward()
Create a ``FeedForward`` object for the fiven constants.

<Tabs
  groupId="FF_constructor_1"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  FeedForward(const double _kv, const double _ks, const double _ka);
```
</TabItem>

<TabItem value="example">
```cpp
lightning::FeedForward speed_controller (5,1000,350); 
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``_kv``  | The velocity constant. |
| ``_ks  ``| The Friction constant. |
| ``_ka `` | Acceleration control. |

---

### FeedForward() copy 
Copy constructor.
<Tabs
  groupId="FF_constructor_copy"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  FeedForward(const FeedForward &other);
```
</TabItem>

<TabItem value="example">
```cpp
   null
```
</TabItem>
</Tabs> 

| Parameters    |  |
| ------------- | ------------- |
| ``other``  | FeedForward object to copy. |

---

## Functions
### update()
Updates the controller.

:::info
You should put this function inside of while loop to update the input to the current reading.
:::

<Tabs
  groupId="FF_functions_update"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  void update(const double input);
```
</TabItem>

<TabItem value="example">
```cpp
   null
```
</TabItem>
</Tabs> 

| Parameters    |  |
| ------------- | ------------- |
| ``input``     | The actual input of the controller. "The current reading" |

---

## Getters
### get_kv()
Get the kv constant.
<Tabs
  groupId="FF_getters_kv"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  double get_kv(void) const;
```
</TabItem>

<TabItem value="example">
```cpp
   null
```
</TabItem>
</Tabs>  

**Returns:** The kv constant. 

### get_ks()
Get the friction constant
<Tabs
  groupId="FF_getters_ks"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  double get_ks(void) const;
```
</TabItem>

<TabItem value="example">
```cpp
   null
```
</TabItem>
</Tabs> 

**Returns:** The ks constant.

### get_ka()
Gets the acceleration constant.
<Tabs
  groupId="FF_getters_ka"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  double get_ka(void) const;
```
</TabItem>

<TabItem value="example">
```cpp
   null
```
</TabItem>
</Tabs> 

**Returns:** The Ka constant. 

### get_output
Gets the current output of the controller.
:::note
You should put this output to your motors
:::
<Tabs
  groupId="FF_getters_output"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  double get_output(void) const;
```
</TabItem>

<TabItem value="example">
```cpp
   null
```
</TabItem>
</Tabs> 

**Returns:** The current output. 