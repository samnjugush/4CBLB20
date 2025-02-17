function rtscope(varargin)

% RTSCOPE  Rtscope experimentation software for use with Simulink

if nargin==1
    qadscope(1, varargin{1})
else
    qadscope(1, '127.0.0.1')
end
