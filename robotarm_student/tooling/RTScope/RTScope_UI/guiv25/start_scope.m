function start_scope()

global g g2;

def=qs_defines;

figure(1)
clf;
set(gcf,'Name','RTScope View');
set(gcf,'DoubleBuffer','on');
pos_gui=get(g2.QS_HANDLES.tag_qlgui,'Position');
%pos_gui(1)=50;
%pos_gui(2)=50;
%set(g.QS_HANDLES.tag_qlgui,'Position',pos_gui);
pos_scope=get(gcf,'Position');
pos_scope(1)=pos_gui(1)+pos_gui(3)+7;
pos_scope(2)=pos_gui(2)+1;
pos_scope(3)=pos_gui(3);
pos_scope(4)=pos_gui(4)-def.MENUBAR_HEIGHT;
set(gcf,'Position',pos_scope);
g2.QS_SCOPE_HDLS=zeros(g.QS_MAXSCOPE,1);
for j=1:g.QS_MAXSCOPE,
    g2.QS_SCOPE_HDLS(j)=subplot(g.QS_MAXSCOPE,1,j);
%    title(sprintf('scope %d',j));
    grid on;
end
