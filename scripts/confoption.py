#-------------------------------------------------------------------------------
# imports
#-------------------------------------------------------------------------------
import os

#===============================================================================
#
# Functions
#
#===============================================================================
#-------------------------------------------------------------------------------
# create
#-------------------------------------------------------------------------------
def create(filename):
    rc = False

    if not os.path.isfile(filename):
        open(filename, 'a').close()
        rc = True

    return rc

#-------------------------------------------------------------------------------
# delete
#-------------------------------------------------------------------------------
def delete(filename):
    if os.path.isfile(filename):
        os.remove(filename)

#-------------------------------------------------------------------------------
# append
#-------------------------------------------------------------------------------
def append(filename, data):
    f = open(filename, 'a')
    f.write(data)
    f.close()

#-------------------------------------------------------------------------------
# prepend
#-------------------------------------------------------------------------------
def prepend(filename, data):
    with open(filename, 'r+') as f:
        content = f.read()
        f.seek(0, 0)
        f.write(data.rstrip('\r\n') + '\n' + content)
    f.close()

#-------------------------------------------------------------------------------
# part_begin
#-------------------------------------------------------------------------------
def part_begin(part):
    return "## %s BEGIN ##\n" % part

#-------------------------------------------------------------------------------
# part_end
#-------------------------------------------------------------------------------
def part_end(part):
    return "## %s END ##\n" % part

#-------------------------------------------------------------------------------
# part_exist
#-------------------------------------------------------------------------------
def part_exist(filename, part):
    rc = False
    if part in open(filename).read():
        rc = True
    return rc

#-------------------------------------------------------------------------------
# part_create
#-------------------------------------------------------------------------------
def part_create(filename, part, begin=False):
    if not part_exist(filename, part):
        if begin == True:
            prepend(filename, part_end(part))
            prepend(filename, part_begin(part))
        else:
            append(filename, part_begin(part))
            append(filename, part_end(part))

#-------------------------------------------------------------------------------
# part_add
#-------------------------------------------------------------------------------
def part_add(filename, part, data):
    if os.path.isfile(filename) and part_exist(filename, part):
        # open file
        f = open(filename, 'r+')

        # want to insert data in part, so we search where to insert in file
        lines = f.readlines()

        try:
            pos = lines.index(part_begin(part))+1
        except:
            # should not be here
            return

        f.close()

        # insert data in list
        lines.insert(pos, "%s\n" % data)

        # delete and recreate the file
        delete(filename)
        create(filename)

        # write the list of lines
        f = open(filename, 'r+')
        for l in lines:
            f.write(l)
        f.close()

#-------------------------------------------------------------------------------
# part_delete
#-------------------------------------------------------------------------------
def part_delete(filename, part):
    if os.path.isfile(filename) and part_exist(filename, part):
        f = open(filename, 'r+')

        lines = f.readlines()
        lines_to_keep = []

        to_rm = False
        end_found = False
        for l in lines:
            if not end_found:
                if l == part_begin(part):
                    to_rm = True
                elif l == part_end(part):
                    end_found = True
            else:
                to_rm = False

            if not to_rm:
                lines_to_keep.append(l)

        f.close()

        delete(filename)
        create(filename)

        f = open(filename, 'r+')
        for l in lines_to_keep:
            f.write(l)
        f.close()
