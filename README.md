libhasso README
===============
:Author:    Alexander Schwoch
:Email:     alex@palc.de
:Date:      12.10.2012
:Revision:  0
:toc:

== Purpose

This library is designed to be used within projects with the need of some basic
functions to authenticate _users_. Users in this context are people who are not 
known to operating system, but to the current program via its own database.

In order to come with very little dependency distinct algorithms are included 
within this library who may reside within several other libraries. However the
goal is to create an easy to use library, and each dependency added will 
increase complexity. There will be interfaces to increase the flexibility of 
the library so that other algorithms may be used without the need to modify 
libhasso.


== License

I am no fan of licences. So I state following terms until I decide which one to
use.

 - You may use the library free of charge within commercial and non commercial
   projects.
   
 - If you distribute programs or source code based on this library you must 
   provide a README file (similar to this one) where you attribute the usage of 
   this library or source code.
   
 - If you alter the source code you must make changes available for everyone as
   soon as you release any piece of your program or sources to the public.
   
 - This source code comes without any warranties. You must not file lawsuits 
   against authors or contributers to this library because of any harm that was
   caused by the use of it.
   
 
== Attributions

This list contains pieces of software I adopted from somewhere else.

:whirpoolUrl:   http://www.larc.usp.br/~pbarreto/WhirlpoolPage.html
:truecryptUrl:  http://www.truecrypt.org

 - Whirlpool is a public domain hash function. Please refer to 
   {whirpoolUrl}[the Whirpool homepage] for more information. I used it with
   the deviations made by {truecryptUrl}[the Truecrpyt authors] so it fits
   better into this C++ project.
   
:asciidocUrl:   http://www.methods.co.nz/asciidoc/index.html
   
 - This documentation was generated or may be transformed with 
   {asciidocUrl}[asciidoc].
   
   
== Documentation

=== Hashing

The interface +IHash<int N>+ is used to pass a hashing algorithm to a function 
which works with hashes. N is the number of bytes the hash results in.

LibHasso uses {whirpoolUrl}[Whirlpool] if nothing else is specified. If you do 
want to use another hash function implement one by creating a class deriving 
from the IHash interface. LibHasso then will operate with this hash algorithm 
transparently.

If you want to create a whirlpool hash you can either use the Whirlpool wrapper
declared in +whirlpoolwrapper.hpp+ or invoke the original functions directly, 
as declared in +whirlpool.h+.
