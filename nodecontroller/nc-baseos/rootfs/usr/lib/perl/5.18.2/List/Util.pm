# List::Util.pm
#
# Copyright (c) 1997-2009 Graham Barr <gbarr@pobox.com>. All rights reserved.
# This program is free software; you can redistribute it and/or
# modify it under the same terms as Perl itself.
#
# This module is normally only loaded if the XS module is not available

package List::Util;

use strict;
require Exporter;

our @ISA        = qw(Exporter);
our @EXPORT_OK  = qw(first min max minstr maxstr reduce sum sum0 shuffle);
our $VERSION    = "1.27";
our $XS_VERSION = $VERSION;
$VERSION    = eval $VERSION;

require XSLoader;
XSLoader::load('List::Util', $XS_VERSION);

sub sum0
{
   return 0 unless @_;
   goto &sum;
}

1;

__END__

