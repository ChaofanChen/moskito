/**************************************************************************/
/*  MOSKITO - Multiphysics cOupled Simulator toolKIT for wellbOres        */
/*                                                                        */
/*  Copyright (C) 2017 by Maziar Gholami Korzani                          */
/*  Karlsruhe Institute of Technology, Institute of Applied Geosciences   */
/*  Division of Geothermal Research                                       */
/*                                                                        */
/*  This file is part of MOSKITO App                                      */
/*                                                                        */
/*  This program is free software: you can redistribute it and/or modify  */
/*  it under the terms of the GNU General Public License as published by  */
/*  the Free Software Foundation, either version 3 of the License, or     */
/*  (at your option) any later version.                                   */
/*                                                                        */
/*  This program is distributed in the hope that it will be useful,       */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          */
/*  GNU General Public License for more details.                          */
/*                                                                        */
/*  You should have received a copy of the GNU General Public License     */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>  */
/**************************************************************************/

#ifndef MOSKITOENTHALPYTEMPERATUREDBC_H
#define MOSKITOENTHALPYTEMPERATUREDBC_H

#include "NodalBC.h"
#include "MoskitoEOS.h"

class MoskitoEnthalpyTemperatureDBC;

template <>
InputParameters validParams<MoskitoEnthalpyTemperatureDBC>();

class MoskitoEnthalpyTemperatureDBC : public NodalBC
{
public:
  MoskitoEnthalpyTemperatureDBC(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  // temperature value
  const Real & _T;

  // Userobject to equation of state
  const MoskitoEOS & _eos_uo;
};

#endif // MOSKITOENTHALPYTEMPERATUREDBC_H
