# 2021 COS30008 - Data Structures & Patterns
This unit focusses on creating data structures that effectively represents a problem, while taking factors like memory space and expandability into consideration.

## Who Am I?

* Name: Khang Gia Trinh
* ID: 102118468
* Email: 102118468@student.swin.edu.au

## Purpose

* This document contains rules and conventions for writing commit messages

## Committing rules
* Where possible, changes should be made in several small commits as it makes it
easy to find the steps in achieving those changes

## Commit Messages
### Use Tags

* ADD: Used for adding something new to the project (ie. New files, new code, etc.)
* FIX: Used for fixing bugs, broken features, tutor's suggestions, etc.
* UPDATE: Used for making changes on an existing file

### Writing rules
The messages must be:
* A summary of 50 chars or less
* Written in imperative mood (ie. Add instead of Added)
* Has no period `.` at the end
* Be as specific as possible

### Examples:
```
5ba3db6 ADD: Ammo reload feature
```
```
e142fd1 FIX: Player vs Bullet collision detection
```
```
22b25e0 UPDATE: Increase Player HP from 80 to 90
```

## Release Notes
* Title must have version number and date

### Version numbering
Example version: x.y.z
* x: Major release (Task number)
* y: Minor release (Total count of additions and updates in that task)
* z: Fixes (Fixes related to that task)

### Listing changes
**At least 1** of these categories must be in each version listed:
  * What's New: A list of all major additions
  * Changes: A list of all major updates
  * Fixes: A list of all bug fixes (major and minor)

### Writing rules
What's New:
* An addition "has been added".
* This feature "is now available".

Changes:
* This feature "has been increased/decreased from x to y".
* This feature "has been removed

Fixes:
* This issue "has been fixed". 
* The player "will now be able to"/"will no longer be able to do x, y, z".
