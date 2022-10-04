
Preface

Learn a new statically typed compiled programming language to build maintainable and fast software with the help of this comprehensive guide to V programming. V programming comes with high performance and simplicity, which allows software programmers to do rapid prototyping of applications at scale.
Who this book is for

This book is for you if you are any of the following:

    A beginner who is interested in learning a programming language that comes with a quick and short learning curve
    An experienced programmer who is looking to switch to a new and better statically typed and compiled programming language
    Willing to write quick and rapid prototyping of applications at scale using a new language with powerful concurrency features

What this book covers

Chapter 1, Introduction to V Programming, introduces the V programming language and its features. It also looks at the past, present, and future of V. Learn about the cross-compatibility of V and the list of operating systems V runs on.

Chapter 2, Installing V Programming, offers step-by-step details that will help you learn how to install the V programming language on the Windows and *nix OSes. You'll also learn how to ensure V is added to environment variables on Windows and symlinking on *nix OS, which will facilitate you accessing V from any directory.

Chapter 3, Variables, Constants, and Code Comments, introduces you to basic programming concepts such as how to define and work with variables and constants in V. This chapter also covers how to add single- and multi-line comments in V.

Chapter 4, Primitive Data Types, acquaints you with the world of primitive data types. You'll come to understand various primitive data types in V such as string, bool, rune, and other numeric types. You'll also learn how to work with these types. This chapter also introduces you to the various operators you can use on these data types such as relational, logical, arithmetic, bitwise, and shift operators. If you are an absolute beginner to the world of software programming, this chapter is highly recommended to get you hands-on with the concepts related to the primitive data types that are similar in all other programming languages.

Chapter 5, Arrays and Maps, covers different ways to declare arrays and how to initialize them using various properties available to define an array. You'll also see how to use in and << operators on arrays. We then walk through the details about working with fixed-size arrays and multi-dimensional arrays. You will also understand arrays by performing the most frequently performed operations on arrays, such as cloning, sorting, and filtering techniques.

You will also learn about maps that hold data in the form of key-value pairs. Maps in the V language are often referred to as dictionaries in other programming languages, such as C# and Python. You will learn how to work with maps, and understand various ways we can declare and initialize maps. You will also learn how to perform various operations on a map, such as retrieving the key-value pair given a key, and handling the retrieval of non-existent keys using an or block. Then you will see how to add, update, and delete key-value pairs from a map.

Chapter 6, Conditionals and Iterative Statements, looks in detail at conditionals and iterative statements in the V programming language. You'll learn about working with conditional blocks such as if, if-else, and chaining else-if along with the usage of goto statements supported by labels. You will also learn in depth about match block, which is used for use cases that involve pattern matching or conditional code branching. In the later parts of this chapter, we will look at the various types of operations performed on maps, arrays using for loops, and then you will see the different ways to write iterative statements using a for loop.

Chapter 7, Functions, introduces the various types of functions V lang offers. You will then be able to write basic functions, anonymous functions, and higher-order functions. This chapter will also guide you through the vast features that functions come equipped with, along with code examples for each feature.

Chapter 8, Structs, looks at how to write structs that involve struct fields having different access modifiers and also defining struct fields with default values. You will then learn the skill of defining and initializing structs. You will then have a fair understanding of how to add methods that belong to a struct and create and work with functions with structs as input arguments.

Chapter 9, Modules, first introduces the basic syntax to define and import modules. In the later sections, you will see how to create a simple project in V, and then learn how to create and import modules defined in our simple project. You will then learn how to create multiple files and work with those in a module and understand the access scope.

You will also learn about best practices that include the benefits of the initializer function and conditions to define the initializer function for a module. This chapter also covers problems that arise in V when we have cyclic imports while creating modules. In addition, you will understand member scopes and the accessibility of members, including constants, structs, and embedded structs across modules. By the end of this chapter, you will be well-versed in the concept of modules and how to leverage them while writing programs in V.

Chapter 10, Concurrency, looks at concurrency, which is a crucial topic when it comes to V. The main essence of V lies in the concurrency capabilities that it offers programmers. In this chapter, you will learn in depth about the concept of concurrency, along with detailed code examples. This chapter begins with an explanation of a simple real-life scenario, which is about performing daily morning routines. The chapter also looks at a comparison of the results of the tasks when they were performed sequentially, and the benefits when similar tasks are performed concurrently.

In addition to the more intuitive explanation on concurrency in this chapter, the chapter sets foundational knowledge on concepts such as time modules and thread types to get started with concurrent programming in V.

By the end of this chapter, you will be confident enough to write concurrent code in V using the go keyword and handling concurrent functions using thread types. You will be able to understand the benefit of writing concurrent code in contrast to sequential code. This chapter will also help you understand how to concurrently spawn void functions, functions that return values as well as anonymous functions. You will also learn how to share data between the main thread and the tasks that are spawned to run concurrently using locks.

Chapter 11, Channels – An Advanced Concurrency Pattern, covers channels, which is the advanced concurrency pattern in V. They solve the problem of explicitly handling data synchronization techniques among coroutines. In the context of concurrency, channels facilitate us to share data by establishing a communication channel between concurrent tasks. These concurrent tasks are often termed coroutines, which share the data by communicating through channels.

We can communicate between coroutines with the help of shared objects. But the problem with this approach is you need to take explicit care of concurrency synchronization techniques such as protecting the shared objects using locks such as the read-only rlock or the read/write lock to prevent data races. This is where channels in V come into the picture. Channels implicitly take care of all the aforementioned data synchronization techniques among coroutines, which otherwise are cumbersome to manage manually.

In this chapter, we begin by looking at the syntax to declare channels and then understand different types of channels, such as buffered and unbuffered channels. We then learn about the properties of channels. Later, we learn about various methods available on a channel.

Chapter 12, Testing, covers how to write test cases for functions in V. This chapter also covers what the minimum prerequisites are for your code and file structure in order for V to identify and run them as tests.

Chapter 13, Introduction to JSON and ORM, explains how to work with the built-in libraries in V, namely json and orm. When building web services such as RESTful APIs, it is essential to understand the content type that you are exchanging with the clients or other RESTful APIs. The JavaScript Object Notation (JSON) format has become the new normal for modern applications to exchange data. This chapter will touch upon a brief introduction to JSON and how to work with JSON in V.

When building data-driven applications, Object Relational Mappers (ORMs) become a crucial part to establish communication between the world of objects and the world of relational databases. This chapter also introduces the built-in library orm, which ships along with the V installer.

Chapter 14, Building a Microservice, looks at how to build a simple microservice in V using a RESTful approach. To achieve the implementation, you will be using the built-in libraries vweb and orm. You will also leverage the power of SQLite, by installing it as a third-party library. With the help of the SQLite library, you will learn how to establish a database connection and interact with it. You will use the JSON data format as a form of communication.
To get the most out of this book

If you are using the digital version of this book, we advise you to type the code yourself or access the code from the book's GitHub repository (a link is available in the next section). Doing so will help you avoid any potential errors related to the copying and pasting of code.
Download the example code files

You can download the example code files for this book from GitHub at https://github.com/PacktPublishing/Getting-Started-with-V-Programming. If there's an update to the code, it will be updated in the GitHub repository.

We also have other code bundles from our rich catalog of books and videos available at https://github.com/PacktPublishing/. Check them out!
Download the color images

We also provide a PDF file that has color images of the screenshots and diagrams used in this book. You can download it here: https://static.packt-cdn.com/downloads/9781839213434_ColorImages.pdf.
Conventions used

There are a number of text conventions used throughout this book.

Code in text: Indicates code words in text, database table names, folder names, filenames, file extensions, pathnames, dummy URLs, user input, and Twitter handles. Here is an example: "The x variable is declared with a value of 100 using the := symbol."

A block of code is set as follows:

const (
    app_name = 'V on Wheels'
    max_connections = 1000
    decimal_places = 2
    pi = 3.14
)

When we wish to draw your attention to a particular part of a code block, the relevant lines or items are set in bold:

import json
fn main() {
	m := Note{
		id: 2
		message: 'Get groceries'
		status: false
	}
	j := json.encode(m)
	println(j)
}

Any command-line input or output is written as follows:

sudo apt -y update sudo apt install -y build-essential

Bold: Indicates a new term, an important word, or words that you see onscreen. For instance, words in menus or dialog boxes appear in bold. Here is an example: "Now select the Body tab, and check the raw radio button."

Tips or important notes

Appear like this.
Get in touch

Feedback from our readers is always welcome.

General feedback: If you have questions about any aspect of this book, email us at customercare@packtpub.com and mention the book title in the subject of your message.

Errata: Although we have taken every care to ensure the accuracy of our content, mistakes do happen. If you have found a mistake in this book, we would be grateful if you would report this to us. Please visit www.packtpub.com/support/errata and fill in the form.

Piracy: If you come across any illegal copies of our works in any form on the internet, we would be grateful if you would provide us with the location address or website name. Please contact us at copyright@packt.com with a link to the material.

If you are interested in becoming an author: If there is a topic that you have expertise in and you are interested in either writing or contributing to a book, please visit authors.packtpub.com.
Share Your Thoughts

Once you've read Getting Started with V Programming, we'd love to hear your thoughts! Please click here to go straight to the Amazon review page for this book and share your feedback.

Your review is important to us and the tech community and will help us make sure we're delivering excellent quality content.
