PEP: NNN
Title: Adding a file system path protocol
Version: $Revision$
Last-Modified: $Date$
Author: Brett Cannon <brett@python.org>
Status: Draft
Type: Standards Track
Content-Type: text/x-rst
Created: DD-Mmm-2016
Post-History: DD-Mmm-2016


Abstract
========

This PEP proposes a protocol for classes which represent a file system
path to follow in order to provide such a path in a lower-level
representation/encoding. Changes to Python's standard library are also
proposed to utilize this protocol where appropriate to facilitate the
use of path-like objects where historically only ``str`` and/or
``bytes`` file system paths are accepted.


Rationale
=========

Historically in Python, file system paths have been represented as
strings or bytes. This choice of representation has stemmed from C's
own decision to represent file system paths as
``const char *`` [#libc-open]_. While that is a totally serviceable
format to use for file system paths, it's not necessarily optimal. At
issue is the fact that while all file system paths can be represented
as strings or bytes, not all strings or bytes represent a file system
path; having a format and structure to file system paths makes their
string/bytes representation act as an encoding.

To help elevate the representation of file system paths from their
encoding as strings and bytes to a more appropriate object
representation, the pathlib module [#pathlib]_ was provisionally
introduced in Python 3.4 through PEP 428. While considered by some as
an improvement over strings and bytes for file system paths, it has
suffered from a lack of adoption. Typically the two key issues listed
for the low adoption rate has been the lack of support in the standard
library and the difficulty of safely extracting the string
representation of the path from a ``pathlib.PurePath`` object in a
safe manner for use in APIs that don't support pathlib objects
natively (as the pathlib module does not support bytes paths,
support for that type has never been a concern).

The lack of support in the standard library has stemmed from the fact
that the pathlib module was provisional. The acceptance of this PEP
will lead to the removal of the module's provisional status, allowing
the standard library to support pathlib object widely.

The lack of safety in converting pathlib objects to strings comes from
the fact that only way to get a string representation of the path was
to pass the object to ``str()``. This can pose a problem when done
blindly as nearly all Python objects have some string representation
whether they are a path or not, e.g. ``str(None)`` will give a result
that ``builtins.open()`` will happily use to create a new file.

This PEP then proposes to introduce a new protocol for objects to
follow which represent file system paths. Providing a protocol allows
for clear signalling of what objects represent file system paths as
well as a way to extract a lower-level encoding that can be used with
older APIs which only support strings or bytes.


Proposal
========

XXX


Open Issues
===========

XXX


Rejected Ideas
==============

XXX


References
==========

.. [#libc-open] ``open()`` documention for the C standard library
(http://www.gnu.org/software/libc/manual/html_node/Opening-and-Closing-Files.html)

.. [#pathlib] The ``pathlib`` module
(https://docs.python.org/3/library/pathlib.html#module-pathlib)


Copyright
=========

This document has been placed in the public domain.



..
   Local Variables:
   mode: indented-text
   indent-tabs-mode: nil
   sentence-end-double-space: t
   fill-column: 70
   coding: utf-8
   End:
