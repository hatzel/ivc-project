#macro make_cable(startpos, startrotation, endpos, endrotation, cableradius, cabletexture)
sphere_sweep {
   cubic_spline
   7,
   startpos, cableradius
   startpos, cableradius
   startpos+startrotation, cableradius
   <(startpos.x+endpos.x)/2, (startpos.y+endpos.y-3)/2, (startpos.z+endpos.z)/2>, cableradius
   endpos-endrotation, cableradius
   endpos, cableradius
   endpos, cableradius
   tolerance 0.1
   texture { cabletexture }
 }
#end
