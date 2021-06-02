#define CloneFunction
#define CopyConstructor
#define AssignmentOperator
#define MoveSemantics
#define StateMachine

#ifdef CloneFunction
//SimpleString *SimpleString::clone() { 
/// return *this as a new thing
//	return new SimpleString(*this); 
//}
#endif

#ifdef CopyConstructor
//SimpleString::SimpleString(const SimpleString &aOtherString) { 

/// Create new memory for data
//	unsigned long lLength = strlen(aOtherString.fCharacters) + 1; 
//	fCharacters = new char[lLength]; 

/// Assign new data to it
//	for (unsigned int i = 0; i < lLength; i++)
//		fCharacters[i] = aOtherString.fCharacters[i]; 

//}
#endif

#ifdef AssignmentOperator
//SimpleString &SimpleString::operator=(const SimpleString &aOtherString) {
/// Check for duplicate
//	if (&aOtherString != this)
//	{
///		Delete
//		delete fCharacters;
// 
///		Copy (Exactly the same as copy constructor) 
//		unsigned long lLength = strlen(aOtherString.fCharacters) + 1; 
//		fCharacters = new char[lLength]; 
//
//		for (unsigned int i = 0; i < lLength; i++)
//			fCharacters[i] = aOtherString.fCharacters[i];
//	}
//	return *this;
//}
#endif

#ifdef MoveSemantics
// Use std::move() to explicitly cast to r-value
// Reminder that l-value is a variable (ie. int a, float b, etc.), and r-value is a literal value (ie. 10, "a word", etc.)
#endif

#ifdef StateMachine
/// Provide an enum populated with states
//	private:
//		enum class States { BEFORE, DATA, AFTER };

#endif