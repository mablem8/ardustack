# Notes for KiCad

* Install the correct version.

```bash
sudo add-apt-repository ppa:kicad/kicad-6.0-releases
sudo apt update
sudo apt install kicad
```

* Open KiCad. If prompted, start with default settings.

* Choose `File > New Project from Template...`. Select
  "Arduino as Uno - Expansion" and choose "OK." Select the project location,
  e.g. `$HOME/git-repos/ardustack/02-processor/kicad/`.
  **Un-check "Create a new directory for the project" (bottom left)** and type
  the project name in the top text box (here: `ardustack-mcu`). Choose "Save."

* Launch the Schematic Editor. If prompted, accept "Copy default global symbol
  library table (recommended)." Choose `File > Save`.

* Open the Symbol Editor by choosing `Tools > Symbol Editor` from the Schematic
  Editor.

* Using the Symbol Editor, choose `File > New Library...`. Choose the "Project"
  scope when prompted. Use the project name (here: `ardustack-mcu`), and choose
  "Save."

* Import the BOM symbols provided by `componentsearchengine.com` (free account
  required). Select `File > Import Symbol...` and save in the project library
  (be sure to select the project library for symbol import). The `.lib` files
  are provided in the `components/` directory.

* Open the Footprint Editor. Accept "Copy default global footprint library table
  (recommended)" if prompted. Choose `File > New Library...`. Choose the
  "Project" scope when prompted. Use the project name (here: `ardustack-mcu`),
  and choose "Save."

* Import the BOM footprints from `componentsearchengine.com` into the project
  footprint library. Right-click on the footprint library, and select
  `Import Footprint...`. The `.kicad_mod` files are provided in the
  `footprints/` directory. Choose `File > Save`, select the footprint library,
  and choose "Save."

* For each footprint, associate the corresponding 3D model from the `3d-models/`
  directory. Choose `File > Footprint Properties...` and specify the path to the
  3D model file under the 3D Settings tab using the folder icon. Save changes.

* Lay out the schematic in the Schematic Editor. At the top right, set P3 1 and
  2 to NCs (X).

* In the Schematic Editor, select `Tools > Annotate Schematic...` and choose
  "Entire schematic;" "Keep existing annotations;" "Sort symbols by X position;"
  and "Use first free number after 0."

* Also in the Schematic Editor, choose `Tools > Assign Footprints...` and set
  the footprints.

* Open the PCB Editor and choose `File > Save`.

* In the Schematic Editor, choose `File > Export > Netlist...` and select
  "Export Netlist."

* In the PCB Editor, choose `File > Import > Netlist...` and browse to the
  appropriate file.

* Place the components, tracks, ground plane, and silkscreen labels.

## Generating Gerbers

* Ensure that fill zones have been redrawn, e.g. by running DRC (the bug icon)
* Choose `File > Plot...` from the PCB Editor
  * Output directory: ../gerbers/
  * Included Layers: F.Cu, B.Cu, F.Silkscreen, B.Silkscreen, F.Mask, B.Mask,
    Edge.Cuts
  * General Options: Plot footprint values, Plot reference designators
  * Gerber Options: Generate Gerber job file
* Choose "Plot"
* Choose "Generate Drill File"
  * Output folder: ../gerbers/
  * Drill File Format: Excellon, PTH and NPTH in single file, Oval Holes Drill
    Mode: Use route command (recommended)
  * Map File Format: PostScript
  * Dill Origin: Absolute
  * Drill Units: Inches
  * Zeros Format: Decimal format (recommended)
* Choose "Generate Drill File"
